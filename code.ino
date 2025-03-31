#include <Servo.h>

// Motor Driver Pins
const int ENA = 5;
const int IN1 = 6;
const int IN2 = 7;
const int IN3 = 8;
const int IN4 = 9;
const int ENB = 10;

// IR Sensor Pins
const int leftSensor = 2;
const int rightSensor = 3;

// Ultrasonic Sensor Pins
const int trigPin = 9;
const int echoPin = 10;

// Servo Pin
const int servoPin = 11;

Servo myServo;

void setup() {
  // Initialize motor driver pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Initialize sensors
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize servo
  myServo.attach(servoPin);
  myServo.write(90); // Set servo to center position

  // Start Serial Communication
  Serial.begin(9600);
}

void loop() {
  int leftStatus = digitalRead(leftSensor);
  int rightStatus = digitalRead(rightSensor);
  int distance = measureDistance();

  if (distance < 20) { // Obstacle detected within 20 cm
    avoidObstacle();
  } else {
    followLine(leftStatus, rightStatus);
  }
}

void followLine(int leftStatus, int rightStatus) {
  if (leftStatus == LOW && rightStatus == LOW) {
    // Move forward
    moveForward();
  } else if (leftStatus == LOW && rightStatus == HIGH) {
    // Turn right
    turnRight();
  } else if (leftStatus == HIGH && rightStatus == LOW) {
    // Turn left
    turnLeft();
  } else {
    // Stop
    stopMotors();
  }
}

int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

void avoidObstacle() {
  stopMotors();
  delay(500);
  moveBackward();
  delay(500);
  stopMotors();
  delay(500);

  // Scan environment
  int leftDistance = scanDirection(150); // Look left
  int rightDistance = scanDirection(30); // Look right

  // Decide direction based on distance
  if (leftDistance > rightDistance) {
    turnLeft();
    delay(500);
  } else {
    turnRight();
    delay(500);
  }
}

int scanDirection(int angle) {
  myServo.write(angle);
  delay(500);
  int distance = measureDistance();
  myServo.write(90); // Reset to center
  return distance;
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
 
::contentReference[oaicite:66]{index=66}
 
