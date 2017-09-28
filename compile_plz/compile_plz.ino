/*
   Main code for PoE Lab 2: 3D Scanner Lab
*/



/*
   Class created in order to be able to handle delays (without using delays) and two servo objects
*/
/*
  class ServoSweep {
    Servo servo;  // makes the servo object
    int pos;  // position of the servo
    int threshold;  // delay
    int increment;
    unsigned long prevMillis; // last change in position

  public:
    ServoSweep() {
      pos = 0;
      threshold = 15;
      increment = 1;
    }

    void Sweep(){
      if((millis() - prevMillis) > threshold) {
        prevMillis = millis();
        pos+=increment;
        servo.write(pos);
        if ((pos >= 180) || (pos <= 0))
        {
          increment = -increment;
        }

      }
    }

  }
*/

// creates servo objects to control a servo
#include <Servo.h>
Servo myservoPan; // turntable aspect
Servo myservoTilt; // turns sensor 'up and down'

// defines pins
const int sensorPin = A0;
int servoPanPin = 9;
int servoTiltPin = 10;

// defines values
float voltage = 0; // need the voltage, not the raw sensor reading
// stores servo positions
int posPan = 0;
int posTilt = 90;
// set up wait threshold and angle increment
const int threshold = 15;
const int increment = 1;

// timing variable (to avoid delays)
unsigned long prevMillis = 0;



void setup() {
  // initializing various pins
  pinMode(sensorPin, INPUT);
  myservoPan.attach(servoPanPin);
  myservoTilt.attach(servoTiltPin);

  // initializing Serial
  Serial.begin(9600);

  // start servos at 0 and 0
  myservoPan.write(posPan);
  myservoTilt.write(posTilt);
}

void loop() {
  // read value from sensor
  printOut();
  for (posPan = 0; posPan <= 180;){
  sweepPan();
  }
  
  sweepTilt();

}

void sweepPan() {
  if ((millis() - prevMillis) > threshold) {
    prevMillis = millis();
    
      posPan += increment;
      myservoPan.write(posPan);
      printOut();
    }
}

void sweepTilt() {
  
      prevMillis = millis();    
      posTilt += increment;
      posPan = 0;
      myservoTilt.write(posTilt);
      myservoPan.write(posPan);
}


void printOut(){
  voltage = analogRead(sensorPin) * 5.0 / 1023.0;
  Serial.print("voltage = ");
  Serial.println(voltage);
  
  Serial.print("theta = ");
  Serial.println(posPan);
  
  Serial.print("phi = ");
  Serial.println(posTilt);
}

/*
void wait(unsigned long prevMillis, int threshold) {
  if (millis() - prevMillis > threshold)
  }
*/

/*
  // pans 180 dgerees by increment of one degree (forward and back)
  for (servoPanPos = 0; servoPanPos <= 180; ++servoPanPos) {
    myservoPan.write(servoPanPos);
    delay(15);
  }
  for (servoPanPos = 180; servoPanPos >= 0; --servoPanPos) {
    myservoPan.write(servoPanPos);
    delay(15);
  }
*/

