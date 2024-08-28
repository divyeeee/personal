import cv2
import mediapipe as mp
import numpy as np
import requests

# MediaPipe hands setup
mp_hands = mp.solutions.hands
mp_drawing = mp.solutions.drawing_utils

# ESP8266 IP address when it is in AP mode
ESP8266_URL = "http://192.168.4.1"  # Default IP for ESP8266 in AP mode

# Function to send command to ESP8266
def send_command_to_esp(command):
    url = f"{ESP8266_URL}/{command}"
    try:
        requests.get(url)
    except:
        print("Failed to send command")

# Hand gesture commands mapping
COMMANDS = {
    "FIVE": "forward",        # Move forward     "ONE": "forward"
    "FIST": "backward",       # Move backward    "TWO": "backward"
    "THUMBS_UP": "left",      # Turn left        "THREE": "left"
    "VICTORY": "right",       # Turn right       "FOUR": "right"
    "OK": "stop"              # Stop             "FIVE": "stop"
}

# Function to recognize hand gestures
def recognize_gesture(hand_landmarks):
    thumb_tip = hand_landmarks.landmark[mp_hands.HandLandmark.THUMB_TIP]
    index_tip = hand_landmarks.landmark[mp_hands.HandLandmark.INDEX_FINGER_TIP]
    middle_tip = hand_landmarks.landmark[mp_hands.HandLandmark.MIDDLE_FINGER_TIP]
    ring_tip = hand_landmarks.landmark[mp_hands.HandLandmark.RING_FINGER_TIP]
    pinky_tip = hand_landmarks.landmark[mp_hands.HandLandmark.PINKY_TIP]

    # Example gesture logic:
    if thumb_tip.y < index_tip.y < middle_tip.y < ring_tip.y < pinky_tip.y: 
        return "FIVE"  # All fingers up
    elif thumb_tip.y > index_tip.y > middle_tip.y > ring_tip.y > pinky_tip.y:
        return "FIST"  # All fingers down (fist)
    elif thumb_tip.y < index_tip.y and pinky_tip.y < index_tip.y:
        return "VICTORY"  # Victory sign (two fingers up)
    elif thumb_tip.x < index_tip.x and thumb_tip.y > index_tip.y:
        return "THUMBS_UP"  # Thumbs up
    elif thumb_tip.y < index_tip.y and middle_tip.y < index_tip.y:
        return "OK"  # OK sign
    return None

cap = cv2.VideoCapture(0)

with mp_hands.Hands(min_detection_confidence=0.7, min_tracking_confidence=0.5) as hands:
    while cap.isOpened():
        ret, frame = cap.read()
        if not ret:
            break

        frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        result = hands.process(frame_rgb)

        if result.multi_hand_landmarks:
            for hand_landmarks in result.multi_hand_landmarks:
                mp_drawing.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)
                gesture = recognize_gesture(hand_landmarks)
                if gesture:
                    command = COMMANDS.get(gesture)
                    if command:
                        #send_command_to_esp(command)
                        print(f"Gesture recognized: {gesture}, Command: {command}")

        cv2.imshow("Gesture Control", frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

cap.release()
cv2.destroyAllWindows()
