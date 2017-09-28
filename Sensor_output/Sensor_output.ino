// defines pins
const int sensorPin = A0;
// defines values
float voltage = 0; // need the voltage, not the raw sensor reading


void setup() {
  // initializing various pins
  pinMode(sensorPin, INPUT);
  
  // initializing Serial
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  voltage = analogRead(sensorPin) * 5.0 / 1023.0;
  Serial.print("voltage = ");
  Serial.println(voltage);
  delay(500);
}
