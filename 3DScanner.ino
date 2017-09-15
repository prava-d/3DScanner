#include <Servo.h>

// creates servo objects to control a servo
Servo myservoPan; // turntable aspect
Servo myservoTilt; // turns sensor 'up and down'

// defines pins
const int sensorPin = A0;
int servoPanPin = 9;
int servoTiltPin = 10;

// defines values
int sensorValue = 0; // stores sensor values
// stores servo positions
int servoPanPos = 0;
int servoTiltPos = 0;

void setup() {
  pinMode(sensorPin, INPUT);
  myservoPan.attach(servoPanPin);
  myservoTilt.attach(servoTiltPin);
}

void loop() {
  // read value from sensor
  sensorValue = analogRead(sensorPin);
}
