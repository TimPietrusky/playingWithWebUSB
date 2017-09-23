#include <DmxSimple.h>
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

  DmxSimple.maxChannel(256);


}

void loop() {


  int brightness;
  
  /* Simple loop to ramp up brightness */
  for (brightness = 0; brightness <= 255; brightness++) {
    
    /* Update DMX channel 1 to new brightness */
    DmxSimple.write(7, brightness);
    DmxSimple.write(8, brightness);
    DmxSimple.write(9, brightness);
    DmxSimple.write(10, brightness);
    DmxSimple.write(11, brightness);
    DmxSimple.write(12, brightness);
    
    /* Small delay to slow down the ramping */
    delay(10);
  }

  
  /*if (Serial && Serial.available()) {

    
    //int byte = Serial.read();
    //Serial.println(incomingByte, DEC);

   // Serial.write(byte);
    //Serial.write("\r\n> ");
    
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(250);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);

    //Serial.write("hello world");
    //Serial.flush();
  }*/
}
