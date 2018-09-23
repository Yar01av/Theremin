#include<CapacitiveSensor.h>

CapacitiveSensor sensor = CapacitiveSensor(4, 2);
const int ledPin = 13;
long value, senseHigh;
long senseLow = 10000;
int waitingTime = 12000;
byte numSamples = 50;
int delta = 200;

void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while(millis() < waitingTime) {
      value = sensor.capacitiveSensorRaw(numSamples);

      if(value > senseHigh) {
          senseHigh = value;
      }
      else if (value < senseLow) {
          senseLow = value;
      }
   Serial.println(value);
   
   delay(15);
   }

   Serial.println(senseLow);
   Serial.println(senseLow);
   Serial.println(senseHigh);
   Serial.println(senseHigh);
   digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = sensor.capacitiveSensorRaw(numSamples);
  Serial.println(value);

  long pitch = map(value, senseLow - delta, senseHigh + delta, 50, 4000);
  tone(12, pitch , 17);
  Serial.print("Pitch: ");
  Serial.println(pitch);

  delay(15);
}
