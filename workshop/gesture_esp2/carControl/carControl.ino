#include <WiFi.h>
//part of ESP32 and ESP8266 Arduino core libbraries annd provide a simple way to connect these microcontrollers to a WiFi network.This library includes all the necessary functions and classes to manage Wi-Fi connectivity, handle network communication, and set up both client and server modes for Wi-Fi.
#define ENA 25
#define ENB 26
//The EN A/B (Enable A/B) pin on a motor driver, such as the popular L298N or L293D motor driver, plays a crucial role in controlling the speed and enabling/disabling the motor connected to channel A/B (usually Motor A/B).

//EN A: Controls Motor A (connected to IN1 and IN2).
//EN B: Controls Motor B (connected to IN3 and IN4).

//Speed control via PWM--The EN A/B pin is often connected to a PWM (Pulse Width Modulation) signal from a microcontroller (like Arduino, ESP32, etc.) to control the speed of Motor A/B.

//By varying the duty cycle of the PWM signal (a value between 0 and 255 on an 8-bit microcontroller), the speed of the motor can be adjusted:
//0% Duty Cycle (LOW): The motor is off.
//100% Duty Cycle (HIGH): The motor runs at full speed.
//Intermediate Values: Controls the speed proportionally.

// Define PWM properties
const int freq = 5000; 
// Frequency in Hz, this means that the PWM signal repeats 5000 times per second, continuous repetition helps maintain smooth and stable control over connected devices, such as regulating the speed of a motor or dimming an LED.

const int resolution = 8; 
// Resolution of 8-bit for duty cycle, provides 256 different (0-255) duty cycle values
const int dutyCycle = 170; 
//here the motor would run around 2/3rd of the max possible speed, varying the value of dutycycle also changes the average speed of the motor.

const char* ssid = "robin";       //Name of your wifi/hotspot
const char* password = "12345678";//password of your wifi/hotspot

WiFiServer server(80);
//create a server that listens for incoming client connections over Wi-Fi on the specified port—in this case, port 80, default port for HTTP traffic.

//Specifying ESP32's digital pins for power transmission to motor driver input pins.
int motorPin1 = 27;
int motorPin2 = 12;
int motorPin3 = 13;
int motorPin4 = 14;

void setup() {
  Serial.begin(115200);
//This begins a serial communication at specified speed(baud rate) of communication, here it's 115200 bits/s.
  
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT); 
  pinMode(motorPin4, OUTPUT);
  pinMode(2, OUTPUT);  // Assuming an LED or similar is connected to pin 2

   // Configure PWM channels
 
  
  // Attach the channels to the GPIO pins (here ENA and ENB pins)for motor speed control
  ledcAttach(ENA , freq , resolution);
  ledcAttach(ENB, freq , resolution);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  //connects ESP32 to the specified ssid(network name) with the given password.
  while (WiFi.status() != WL_CONNECTED) {
  //displays the message until ESP32 is connected to the network in the serial monitor.
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  //message to denote that our ESP32 is connected and 
  Serial.println("Connected to WiFi"); 
  server.begin();//starts the server and begins listening for incoming connections on the specified port.
  Serial.println("Server started");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());//prints the IP address assigned to ESP by the host.
}

void loop() {
  WiFiClient client = server.available();
/*checks if any new clients are attempting to connect to the server.
If a client is connected, it returns a WiFiClient object representing that client. If no client is connected, it returns an empty client object.*/
  if (client) {
    Serial.println("New client connected");
    digitalWrite(2, HIGH); // Turn on the LED or signal that client connected

    while (client.connected()) {//checks whether the connected client is still connected to the server,
      if (client.available()) {//checks if there is data available to read from a connected client
        String request = client.readStringUntil('\r');
        //reads the data sent by the client, here our laptops, in string format until it encounters'\r' in the sent data. Then it assigns the sent data to String variable request.
        Serial.print("Received command: ");
        Serial.println(request);

        if (request.endsWith("one")) {
        //If our stored data ends with "one", for example: data sent to ESP by our laptop is in form of "\x0one\r", then request variable stores it as "\x0one"
          Serial.println("Command: Move Forward");
          moveForward();

        } else if (request.endsWith("two")) {
          Serial.println("Command: Turn Right");
          turnRight();

        } else if (request.endsWith("three")) {
          Serial.println("Command: Turn Left");
          turnLeft();
          

        } else if (request.endsWith("four")) {
          Serial.println("Command: Move Backward");
          moveBackward();

        } else if (request.endsWith("zero")) {
          Serial.println("Command: Stop");
          stopMoving();
        }
      }
    }
    client.stop();//closes the connection with the client(here laptop)
    digitalWrite(2, LOW);  // Turn off the LED or signal client disconnection
    Serial.println("Client disconnected");
  }
}

// Function to move the robot forward
void moveForward() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  ledcWrite(ENA, dutyCycle);
  ledcWrite(ENB, dutyCycle);
  Serial.println("Moving Forward");
}

// Function to move the robot backward
  
void moveBackward() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  ledcWrite(ENA, dutyCycle);
  ledcWrite(ENB, dutyCycle);
  Serial.println("Moving Backward");
}

// Function to turn the robot left
void turnLeft() {;
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4,LOW);
  ledcWrite(ENA, dutyCycle);
  ledcWrite(ENB, dutyCycle);
  Serial.println("Turning Left");
}

// Function to turn the robot right
void turnRight() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  ledcWrite(ENA, dutyCycle);
  ledcWrite(ENB, dutyCycle);
  Serial.println("Turning Right");
}

// Function to stop the robot
void stopMoving() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  
  Serial.println("Stopping");
}
