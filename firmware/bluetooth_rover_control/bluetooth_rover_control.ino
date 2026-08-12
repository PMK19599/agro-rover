/*
  Agro Rover — Bluetooth Movement Controller

  Hardware:
  - Arduino-compatible board
  - HC-05 Bluetooth module
  - L298N motor driver
  - Four DC motors

  Bluetooth commands:
  F = Forward
  B = Backward
  L = Left
  R = Right
  G = Forward-left
  I = Forward-right
  H = Backward-left
  J = Backward-right
  S = Stop
  0–9 and q = Speed control

  This firmware is based on the Bluetooth-control program published by
  Make DIY / CircuitBest:
  https://circuitbest.com/category/arduino-projects/

  The referenced program permits remixing and modification but prohibits
  commercial use. This file should therefore not be treated as covered by
  the repository's MIT License.
*/

const int MOTOR_LEFT_FORWARD = 5;
const int MOTOR_LEFT_BACKWARD = 6;
const int MOTOR_RIGHT_FORWARD = 10;
const int MOTOR_RIGHT_BACKWARD = 11;
const int STATUS_LED = 13;

char command = 'S';
int motorSpeed = 204;
int turnSpeed = 0;

void setup() {
  pinMode(MOTOR_LEFT_FORWARD, OUTPUT);
  pinMode(MOTOR_LEFT_BACKWARD, OUTPUT);
  pinMode(MOTOR_RIGHT_FORWARD, OUTPUT);
  pinMode(MOTOR_RIGHT_BACKWARD, OUTPUT);
  pinMode(STATUS_LED, OUTPUT);

  Serial.begin(9600);
  stopRover();
}

void loop() {
  if (Serial.available() <= 0) {
    return;
  }

  command = Serial.read();

  switch (command) {
    case 'F':
      moveForward();
      break;
    case 'B':
      moveBackward();
      break;
    case 'L':
      turnLeft();
      break;
    case 'R':
      turnRight();
      break;
    case 'G':
      moveForwardLeft();
      break;
    case 'I':
      moveForwardRight();
      break;
    case 'H':
      moveBackwardLeft();
      break;
    case 'J':
      moveBackwardRight();
      break;
    case 'S':
      stopRover();
      break;
    case '0':
      motorSpeed = 100;
      break;
    case '1':
      motorSpeed = 140;
      break;
    case '2':
      motorSpeed = 153;
      break;
    case '3':
      motorSpeed = 165;
      break;
    case '4':
      motorSpeed = 178;
      break;
    case '5':
      motorSpeed = 191;
      break;
    case '6':
      motorSpeed = 204;
      break;
    case '7':
      motorSpeed = 216;
      break;
    case '8':
      motorSpeed = 229;
      break;
    case '9':
      motorSpeed = 242;
      break;
    case 'q':
      motorSpeed = 255;
      break;
  }
}

void moveForward() {
  stopRover();
  analogWrite(MOTOR_LEFT_FORWARD, motorSpeed);
  analogWrite(MOTOR_RIGHT_FORWARD, motorSpeed);
}

void moveBackward() {
  stopRover();
  analogWrite(MOTOR_LEFT_BACKWARD, motorSpeed);
  analogWrite(MOTOR_RIGHT_BACKWARD, motorSpeed);
}

void turnLeft() {
  stopRover();
  analogWrite(MOTOR_LEFT_BACKWARD, motorSpeed);
  analogWrite(MOTOR_RIGHT_FORWARD, motorSpeed);
}

void turnRight() {
  stopRover();
  analogWrite(MOTOR_LEFT_FORWARD, motorSpeed);
  analogWrite(MOTOR_RIGHT_BACKWARD, motorSpeed);
}

void moveForwardLeft() {
  stopRover();
  analogWrite(MOTOR_LEFT_FORWARD, turnSpeed);
  analogWrite(MOTOR_RIGHT_FORWARD, motorSpeed);
}

void moveForwardRight() {
  stopRover();
  analogWrite(MOTOR_LEFT_FORWARD, motorSpeed);
  analogWrite(MOTOR_RIGHT_FORWARD, turnSpeed);
}

void moveBackwardLeft() {
  stopRover();
  analogWrite(MOTOR_LEFT_BACKWARD, turnSpeed);
  analogWrite(MOTOR_RIGHT_BACKWARD, motorSpeed);
}

void moveBackwardRight() {
  stopRover();
  analogWrite(MOTOR_LEFT_BACKWARD, motorSpeed);
  analogWrite(MOTOR_RIGHT_BACKWARD, turnSpeed);
}

void stopRover() {
  analogWrite(MOTOR_LEFT_FORWARD, 0);
  analogWrite(MOTOR_LEFT_BACKWARD, 0);
  analogWrite(MOTOR_RIGHT_FORWARD, 0);
  analogWrite(MOTOR_RIGHT_BACKWARD, 0);
}
