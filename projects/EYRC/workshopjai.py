import cv2
import mediapipe as mp
import socket

# Initialize MediaPipe Hands
mp_hands = mp.solutions.hands
hands = mp_hands.Hands(static_image_mode=False,
                       max_num_hands=2,
                       min_detection_confidence=0.5,
                       min_tracking_confidence=0.5)

# Initialize MediaPipe Drawing utility
mp_drawing = mp.solutions.drawing_utils

# Function to count fingers
def count_fingers(landmarks):
    finger_tips = [8, 12, 16, 20]  # Index of finger tips in landmarks
    finger_base = [5, 9, 13, 17]   # Index of finger base in landmarks
    
    count = 0
    for tip, base in zip(finger_tips, finger_base):
        # Check if the tip is above the base in y-axis for finger counting
        if landmarks[tip].y < landmarks[base].y:
            count += 1

    return count

# Establish TCP connection to the ESP
esp_ip = '192.168.137.100'
esp_port = 80

# Keep the socket connection open during the whole session
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((esp_ip, esp_port))
    
    cap = cv2.VideoCapture(0)
    last_message = b"none"

    while cap.isOpened():
        ret, frame = cap.read()
        if not ret:
            print("error")
            break

        # Flip the frame horizontally for natural viewing
        frame = cv2.flip(frame, 1)

        # Convert the BGR image to RGB
        rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

        # Process the frame with MediaPipe Hands
        results = hands.process(rgb_frame)

        if results.multi_hand_landmarks:
            for hand_landmarks in results.multi_hand_landmarks:
                # Draw hand landmarks on the frame
                mp_drawing.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)

                # Convert hand landmarks to a list of (x, y) coordinates
                landmarks = hand_landmarks.landmark

                # Count fingers
                fingers = count_fingers(landmarks)

                # Display the number of fingers detected
                cv2.putText(frame, f"Fingers: {fingers}", (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2)

                # Determine the message to send based on the number of fingers
                message = b"none"
                match fingers:
                    case 1:
                        message = b"one"
                        if message != last_message:
                            s.send(message)
                            last_message = message
                    case 2:
                        message = b"two"
                        if message != last_message:
                            s.send(message)
                            last_message = message
                    case 3:
                        message = b"three"
                        if message != last_message:
                            s.send(message)
                            last_message = message
                    case 4:
                        message = b"four"
                        if message != last_message:
                            s.send(message)
                            last_message = message
 
        cv2.imshow('Frame', frame)

        # Break the loop if 'q' is pressed
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()
    hands.close()
