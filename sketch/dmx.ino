#include <WebUSB.h>
#include <Conceptinetics.h>

WebUSB WebUSBSerial(1, "localhost:8081");
#define Serial WebUSBSerial

// Amount of DMX channels
#define channels 512

// channels: Amounf of DMX channels
// 2: Pin to do read / write operations on the shield
// https://sourceforge.net/p/dmxlibraryforar/wiki/DMX%20Master/
DMX_Master dmx_master(channels , 2);

// Amount of incoming bytes via WebUSB
// Array of bytes
byte incoming[channels];
int channel;



// Run once on startup
void setup() {
  // Wait until WebUSB connection is established
  while (!Serial) {
    ;
  }
  // Data rate in bits per second
  // https://www.arduino.cc/en/Serial/Begin
  // nBytes (per message) * fps * bit (byte into bit conversion)
  //Serial.begin(nBytes * 30 * 8);
  //Serial.begin(9600);

  // Write binary data to WebUSB
  // https://www.arduino.cc/en/Serial/Write
  Serial.write("USB connection is ready.\r\n> ");

  // Waits until transmission to WebUSB is complete
  // https://www.arduino.cc/en/Serial/Flush
  Serial.flush();

  // Start DMXMaster & transmission to DMXShield
  dmx_master.enable();
}



// Run over and over again
void loop() {

  // WebUSB is available
  if (Serial.available() > 0) {

    // Read an amount of nBytes from WebUSB and save them into incoming
    Serial.readBytes(incoming, channels);

    // Set values for a fixture that starts at channel 7
    channel = 7 - 1;
    // Red
    dmx_master.setChannelValue(channel + 1, incoming[0]);
    // Green
    dmx_master.setChannelValue(channel + 2, incoming[1]);
    // Blue
    dmx_master.setChannelValue(channel + 3, incoming[2]);
    // UV
    dmx_master.setChannelValue(channel + 4, incoming[3]);
    // Dimmer
    dmx_master.setChannelValue(channel + 5, incoming[4]);
    // Strobe
    dmx_master.setChannelValue(channel + 6, incoming[5]);

    // Set values for a fixture that starts at channel 13
    channel = 13 - 1;
    // Red
    dmx_master.setChannelValue(channel + 1, incoming[0]);
    // Green
    dmx_master.setChannelValue(channel + 2, incoming[1]);
    // Blue
    dmx_master.setChannelValue(channel + 3, incoming[2]);
    // UV
    dmx_master.setChannelValue(channel + 4, incoming[3]);
    // Dimmer
    dmx_master.setChannelValue(channel + 5, incoming[4]);
    // Strobe
    dmx_master.setChannelValue(channel + 6, incoming[5]);

    // Write back to WebUSB
//    Serial.write("r: ");
//    Serial.write(incoming[0]);
//    Serial.write(" g: ");
//    Serial.write(incoming[1]);
//    Serial.write(" b: ");
//    Serial.write(incoming[2]);
//    Serial.write(" uv: ");
//    Serial.write(incoming[3]);
//    Serial.write(" dimmer: ");
//    Serial.write(incoming[4]);
//    Serial.write(" strobe: ");
//    Serial.write(incoming[5]);

    Serial.print("channels: ");
    Serial.print(channels);
    Serial.flush();

  }
}
