#include <Arduino.h>
int in1 = 0;
int in2 = 1;
int motorPin = 2;
// put function declarations here:


void setup() {
  // put your setup code here, to run once:
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(motorPin, OUTPUT);


}

void loop() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(motorPin, HIGH);
  // put your main code here, to run repeatedly:
}

