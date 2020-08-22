/*
LDR -> 5V
LDR+10K Resistor -> A0
10K Resistor -> GND
*/

const int ledPin = 13;
const int ldrPin = A0;

void setup() {
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(ldrPin, INPUT);
}

void loop() {
int ldrStatus = analogRead(ldrPin);

if (ldrStatus <=300) {
  digitalWrite(ledPin, HIGH);
  Serial.println("LDR is DARK, LED is ON");
  //Serial.println(ldrStatus);
}

else {
  digitalWrite(ledPin, LOW);
  Serial.println("LED is OFF");
  }
}
