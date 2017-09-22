
#include <WebUSB.h>


WebUSB WebUSBSerial(1, "localhost:8081");

#define Serial WebUSBSerial

void setup() {
  while (!Serial) {
    ;
  }
  Serial.begin(9600);
  Serial.write("USB connection is ready.\r\n> ");
  Serial.flush();
  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial && Serial.available()) {
    //int byte = Serial.read();
    //Serial.println(incomingByte, DEC);

   // Serial.write(byte);
    //Serial.write("\r\n> ");
    
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);

    //Serial.write("hello world");
    //Serial.flush();
  }
}
