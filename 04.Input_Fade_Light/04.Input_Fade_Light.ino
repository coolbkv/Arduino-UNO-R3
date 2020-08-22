int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is

void setup() {
  Serial.begin(9600);
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

char rx_byte = 0;
int x = 0;

void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);
  
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
    x = rx_byte - 48; //Convert char to Number
  
    // check if a number was received
    if ((rx_byte >= '1') && (rx_byte <= '9')) {
      Serial.print("On: ");
      Serial.println(rx_byte);
      brightness = 28*x;
      Serial.println(x);
    }
    else {
      Serial.print("Off:");
      Serial.println(rx_byte);
      brightness = 0;
    }
  } // end: if (Serial.available() > 0)
  delay(1000);
  //analogWrite(led, 0);
  //delay(1000);
}
