/*
 * Main code for PoE Lab 2: 3D Scanner Lab
 */



/*
 * Class created in order to be able to handle delays (without using delays) and two servo objects
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
int servoPanPos = 0;
int servoTiltPos = 0;

// timing variable (to avoid delays)
unsigned long prevMillis = 0;



void setup() {
  // initializing various pins
  pinMode(sensorPin, INPUT);
  myservoPan.attach(servoPanPin);
  myservoTilt.attach(servoTiltPin);

  // initializing Serial
  Serial.begin(9600);
}

void loop() {
  // read value from sensor
  voltage = analogRead(sensorPin)*5.0/1023.0;
  
  Serial.print("voltage = ");
  Serial.println(voltage);


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

}
/*
void wait(unsigned long prevMillis, int threshold) {
  if (millis() - prevMillis > threshold)
  }
  */
