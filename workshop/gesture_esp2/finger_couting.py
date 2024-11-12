#!/usr/bin/env python3
import cv2
import mediapipe as mp
import socket

# Establish TCP connection to the ESP
esp_ip = '192.168.137.231'
esp_port = 80

mp_hands = mp.solutions.hands
mp_drawing = mp.solutions.drawing_utils

width = 1280
height = 720

cam = cv2.VideoCapture(0, 0)
cam.set(cv2.CAP_PROP_FRAME_WIDTH, width)
cam.set(cv2.CAP_PROP_FRAME_HEIGHT, height)
cam.set(cv2.CAP_PROP_FPS, 30)
cam.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'MJPG'))
last_message = b"none"

# with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
#     s.connect((esp_ip, esp_port))

with mp_hands.Hands(min_detection_confidence=0.7, min_tracking_confidence=0.5,max_num_hands=1) as hands:
    print(cam.isOpened())
    while cam.isOpened():
        ret, frame = cam.read()
        print(ret)
        if not ret:
            break

        frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        results = hands.process(frame_rgb)
        finger_count = 0

        if results.multi_hand_landmarks:
            for hand_landmarks in results.multi_hand_landmarks:
                mp_drawing.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)

                finger_tips = [mp_hands.HandLandmark.INDEX_FINGER_TIP,
                                mp_hands.HandLandmark.MIDDLE_FINGER_TIP,
                                mp_hands.HandLandmark.RING_FINGER_TIP,
                                mp_hands.HandLandmark.PINKY_TIP]
                
                # Count fingers
                for tip in finger_tips:
                    if hand_landmarks.landmark[tip].y < hand_landmarks.landmark[tip - 2].y:
                        finger_count += 1

                # Thumb detection based on handedness
                handedness = results.multi_handedness[0].classification[0].label
                thumb_tip = mp_hands.HandLandmark.THUMB_TIP
                thumb_ip = mp_hands.HandLandmark.THUMB_IP

                if (handedness == 'Left' and hand_landmarks.landmark[thumb_tip].x > hand_landmarks.landmark[thumb_ip].x) or \
                    (handedness == 'Right' and hand_landmarks.landmark[thumb_tip].x < hand_landmarks.landmark[thumb_ip].x):
                    finger_count += 1

                # Display finger count
                if 0 < finger_count <= 4:
                    cv2.putText(frame, f"{finger_count}", (10, 70), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2, cv2.LINE_AA)
                    # Determine the message to send based on the number of fingers
                    message = b"none"
                    match finger_count:
                        case 1:
                            message = b"one"
                        case 2:
                            message = b"two"
                        case 3:
                            message = b"three"
                        case 4:
                            message = b"four"
                    
                    if message != last_message:
                        #s.sendall(message + b"\r")
                        last_message = message

                else:
                    cv2.putText(frame, "Invalid Gesture", (10, 70), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2, cv2.LINE_AA)
                    message = b"zero\r"
                    if message != last_message:
                        #s.sendall(message)
                        last_message = message

        cv2.imshow('Finger Count', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

cam.release()
cv2.destroyAllWindows()