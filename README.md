# WebUSB
Playing around with WebUSB

* Spec: https://wicg.github.io/webusb/

# Arduino

---

## IDE

1. Find out which Arduino you are using or to which Arduino your microcontroller is compatible to
2. [Use the instructions](https://www.arduino.cc/en/Guide/HomePage) provided for your model to configure Arduino IDE
3. Have fun!

---

## Coding Reference

* https://www.arduino.cc/en/Reference/HomePage

## Shields

### 2.5kV Isolated DMX 512

* Shield: https://www.tindie.com/products/Conceptinetics/25kv-isolated-dmx-512-shield-for-arduino-r2/
* http://dmxshield.blogspot.de/2013/04/conceptinetics-dmx-library-for-arduino.html#comment-form

### Library

* Download the lib: https://sourceforge.net/projects/dmxlibraryforar/
* Install the lib into your Arduino library folder
* Make these changes in
`
// Fix some settings for Arduino Leonardo ETH  https://sourceforge.net/p/dmxlibraryforar/wiki/Getting%20DMX%20library%20to%20work%20on%20Arduino%20Leonardo/
// Comment this line
// #define USE_DMX_SERIAL_0

// Uncomment this line
#define USE_DMX_SERIAL_1

// Decrease the length of the automatic baudrate breaks  
// Comment this line
// #define DMX_BREAK_RATE 	 	    49950

// Uncomment this line
#define DMX_BREAK_RATE 	 	    99900
`

* Set `DMX_BREAK_RATE` to `99900` in `Conceptinetics.h`
* Documentation: https://sourceforge.net/p/dmxlibraryforar/wiki/



---

# Helper

## Convert decimal to hex

If your decimal is *34*, you can convert it into hex in the terminal by using:

```
echo "obase=16; 34" | bc
```

# MacOS

## Find the USB device

```
ioreg -p IOUSB -w0 -l
```

This will list all USB devices, for example:

```
    +-o Arduino Micro@14100000  <class AppleUSBDevice, id 0x100002626, registered, matched, active, busy 0 (40 ms), retain 22>
        {
          "sessionID" = 119957228755640
          "iManufacturer" = 1
          "bNumConfigurations" = 1
          "idProduct" = 32823
          "bcdDevice" = 256
          "Bus Power Available" = 500
          "USB Address" = 21
          "bMaxPacketSize0" = 64
          "iProduct" = 2
          "iSerialNumber" = 3
          "bDeviceClass" = 239
          "Built-In" = No
          "locationID" = 336592896
          "bDeviceSubClass" = 2
          "bcdUSB" = 528
          "USB Product Name" = "Arduino Micro"
          "PortNum" = 1
          "non-removable" = "no"
          "IOCFPlugInTypes" = {"9dc7b780-9ec0-11d4-a54f-000a27052861"="IOUSBFamily.kext/Contents/PlugIns/IOUSBLib.bundle"}
          "bDeviceProtocol" = 1
          "IOUserClientClass" = "IOUSBDeviceUserClientV2"
          "IOPowerManagement" = {"DevicePowerState"=0,"CurrentPowerState"=3,"CapabilityFlags"=65536,"MaxPowerState"=4,"DriverPowerState"=3}
          "Device Speed" = 1
          "USB Vendor Name" = "Arduino LLC"
          "idVendor" = 9025
          "IOGeneralInterest" = "IOCommand is not serializable"
          "USB Serial Number" = "WUART"
          "IOClassNameOverride" = "IOUSBDevice"
        }
```

## Find your product

* The ID of the USB device Vendor (for example Arduino LLC): idVendor
* The ID of the USB device: idProduct

This value can be converted to hex.

# Resources

* [JavaScript powered Arduino with Johnny-Five](https://www.safaribooksonline.com/blog/2013/07/16/javascript-powered-arduino-with-johnny-five/)
