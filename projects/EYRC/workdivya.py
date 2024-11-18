import cv2
import mediapipe as mp
import numpy as np
import requests
import time

# MediaPipe hands setup
mp_hands = mp.solutions.hands
mp_drawing = mp.solutions.drawing_utils
COMMANDS = {
    0: "stop",        # No fingers extended: Stop
    1: "forward",        # One finger extended: Turn left
    2: "right",       # Two fingers extended: Turn right
    3: "left",    # Three fingers extended: Move backward
    4: "back",     # Four fingers extended: Move forward
    5: "stop"         # All five fingers extended: Stop (for safety)
}
# ESP8266 IP address when it is in AP mode  # Default IP for ESP8266 in AP mode
ESP8266_URL = "10.42.0.228:80"
# Function to send command to ESP8266
def send_command_to_esp(command):
    url = f"{ESP8266_URL}/{command}"
    try:
        # Set a timeout to prevent hanging
        response = requests.get(url,timeout=0.1)
        if response.status_code == 200:
            print(f"Command {COMMANDS.get(command)} sent successfully")
            return
        else:
            print(f"Failed to send command {COMMANDS.get(command)}: {response.status_code}")
            return
    except requests.exceptions.Timeout:
        print(f"Timeout occurred while sending command {COMMANDS.get(command)}")
        return
    except requests.exceptions.RequestException as e:
        print(f"Error occurred: {e}")
        return

# Hand gesture commands mapping based on number of fingers extended


# Function to count the number of fingers extended
def count_fingers(hand_landmarks):
    thumb_tip = hand_landmarks.landmark[mp_hands.HandLandmark.THUMB_TIP]
    thumb_ip = hand_landmarks.landmark[mp_hands.HandLandmark.THUMB_IP]
    index_tip = hand_landmarks.landmark[mp_hands.HandLandmark.INDEX_FINGER_TIP]
    index_dip = hand_landmarks.landmark[mp_hands.HandLandmark.INDEX_FINGER_DIP]
    middle_tip = hand_landmarks.landmark[mp_hands.HandLandmark.MIDDLE_FINGER_TIP]
    middle_dip = hand_landmarks.landmark[mp_hands.HandLandmark.MIDDLE_FINGER_DIP]
    ring_tip = hand_landmarks.landmark[mp_hands.HandLandmark.RING_FINGER_TIP]
    ring_dip = hand_landmarks.landmark[mp_hands.HandLandmark.RING_FINGER_DIP]
    pinky_tip = hand_landmarks.landmark[mp_hands.HandLandmark.PINKY_TIP]
    pinky_dip = hand_landmarks.landmark[mp_hands.HandLandmark.PINKY_DIP]

    fingers = [thumb_tip.x > thumb_ip.x,  # Thumb: Extended if tip is to the right of IP (for right hand)
               index_tip.y < index_dip.y,  # Index finger: Extended if tip is above DIP
               middle_tip.y < middle_dip.y,  # Middle finger: Extended if tip is above DIP
               ring_tip.y < ring_dip.y,  # Ring finger: Extended if tip is above DIP
               pinky_tip.y < pinky_dip.y]  # Pinky finger: Extended if tip is above DIP

    return fingers.count(True)

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
                num_fingers = count_fingers(hand_landmarks)
                command = COMMANDS.get(num_fingers)
                if command:
                    #time.sleep(0.05)
                    #send_command_to_esp(num_fingers)
                    print(f"Fingers: {num_fingers}, Command: {command}")

        cv2.imshow("Gesture Control", frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

cap.release()
cv2.destroyAllWindows()
