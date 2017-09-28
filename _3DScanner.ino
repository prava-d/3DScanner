// creates servo objects to control a servo

#include <Servo.h>
Servo myservoPan;  // pan mechanism
Servo myservoTilt;  //  tilt mechanism

// defines pins
const int sensorPin = A0;
const int servoPanPin = 9;
const int servoTiltPin = 10;

// define misc. values
float voltage = 0; // average of all the data points, need volts also not raw sensor readings

// takes five data points in order to average them later
float data1 = 0;
float data2 = 0;
float data3 = 0;
float data4 = 0;
float data5 = 0;

// stores servo positions
byte panPos = 0;
byte tiltPos = 0;

void setup() {

  // initializing pins
  pinMode(sensorPin, INPUT);
  myservoPan.attach(servoPanPin);
  myservoTilt.attach(servoTiltPin);

  // initializing Serial
  Serial.begin(9600);

  // starts both servos at 0
  myservoPan.write(0);
  myservoTilt.write(0);
}

void loop() {
    
    // pans the sensor/servo
    // delays included so it doesn't print too fast and also the servo doesn't move too fast
    for (panPos = 0; panPos <= 180; panPos+=1) {
      Serial.print(panPos);
      Serial.print(',');
      delay(20);
      myservoPan.write(panPos);
      delay(20);
      
      // tilts the sensor/servo (up and down) and takes sensor readings
      for (tiltPos = 0; tiltPos <= 180; tiltPos+=1) {
        Serial.print(tiltPos);
        Serial.print(',');
        delay(20);
        myservoTilt.write(tiltPos);
        delay(20);
        
        // need about 40 ms in order to accurately get the data
        data1 = analogRead(sensorPin);
        delay(40);
        data2 = analogRead(sensorPin);
        delay(40);
        data3 = analogRead(sensorPin);
        delay(40);
        data4 = analogRead(sensorPin);
        delay(40);
        data5 = analogRead(sensorPin);
        delay(20);
        
        voltage = (data1 + data2 + data3 + data4 + data5)/5  * 5.0 / 1023.0; // averages out all the data points, converts to voltage
        Serial.print(voltage);
        Serial.print(', ');
        Serial.print('\n');
      }
      
      // sweeps back (didn't want the servo to move back super quick - seems bad for the system)
      for (tiltPos = 180; tiltPos >= 0; tiltPos-=1) {
        myservoTilt.write(tiltPos);
        delay(20);
      }
    }
    
    // sweeps back for the pan mechanism insteah
    for (panPos = 180; panPos >= 0; panPos-=1) {
     myservoPan.write(panPos); 
      delay(20);
    }

}

