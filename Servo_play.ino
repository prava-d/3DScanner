#include <Servo.h>

Servo arpan; //create servo object
Servo tiltAWhirl;
int panPos = 0;
int tiltPos = 0;

void setup() {
  // put your setup code here, to run once:
  arpan.attach(13); //pan servo is this pin
  tiltAWhirl.attach(12);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
for (panPos = 0; panPos <= 180;){
  panPos +=2;
  arpan.write(panPos);
  delay(10);
  Serial.print("panPos is: ");
  Serial.print(panPos);
  Serial.println(" and increasing");
}
for (panPos = 180; panPos >= 0;){
  panPos -= 2;
  arpan.write(panPos);
  delay(10);
  Serial.print("panPos is: ");
  Serial.print(panPos);
  Serial.println(" and decreasing");
}
for (tiltPos = 0; tiltPos <= 180;){
  tiltPos +=3;
  tiltAWhirl.write(tiltPos);
  delay(10);
  Serial.print("tiltPos is: ");
  Serial.print(tiltPos);
  Serial.println(" and increasing");
}
for (tiltPos = 180; tiltPos >= 0;){
  tiltPos -= 3;
  tiltAWhirl.write(tiltPos);
  delay(10);
  Serial.print("tiltPos is: ");
  Serial.print(tiltPos);
  Serial.println(" and decreasing");
}
}
