void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

char rx_byte = 0;

void loop() {
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
  
    // check if a number was received
    if ((rx_byte >= '0') && (rx_byte <= '9')) {
      Serial.print("Number received: ");
      Serial.println(rx_byte);
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else {
      Serial.print("This is not a number:");
      Serial.println(rx_byte);
      digitalWrite(LED_BUILTIN, LOW);
    }
  } // end: if (Serial.available() > 0)
}
