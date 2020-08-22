/*
LDR -> 5V
LDR+10K Resistor -> A0
10K Resistor -> GND
*/

const int ldrPin = A0;
int buzzer = 13;//the pin of the active buzzer

void setup() {
Serial.begin(9600);
//pinMode(ledPin, OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(ldrPin, INPUT);
}

void loop() {
int ldrStatus = analogRead(ldrPin);

if (ldrStatus <=300) {
  unsigned char i;
  while(analogRead(ldrPin)<=300)
  {
    //output an frequency
    for(i=0;i<80;i++)
    {
      digitalWrite(buzzer,HIGH);
      delay(1);//wait for 1ms
      digitalWrite(buzzer,LOW);
      delay(1);//wait for 1ms
    }
    //output another frequency
    for(i=0;i<100;i++)
    {
      digitalWrite(buzzer,HIGH);
      delay(2);//wait for 2ms
      digitalWrite(buzzer,LOW);
      delay(2);//wait for 2ms
    }
  }
}

else {
  noTone(buzzer);
  Serial.println("LED is OFF");
  }
}
