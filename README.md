# RFID-RC522
This is the arduino code to read RFID card using RC-522 RFID module.

The link to the module: https://www.aliexpress.com/store/product/High-Quality-MFRC-522-RC522-RFID-Reader-RF-IC-Card-Inductive-Sensor-Module-For-Arduino-Module/1827386_32657638702.html (I do not endorse this link personally. it is only for your reference.)

This code uses Software SPI pins instead of the HARDWARE SPI pins of the Arduino. i.e. your SPI pins are not fixed, any digital pin of the arduino can be configured to act as any SPI pin.
The code uses DigitalIO library to make use of the Software SPI functionality.

This code has been tested on Arduino Uno and Arduino Nano boards.

# DigitalIO
The digitalIO library can be found at: https://github.com/greiman/DigitalIO
Download this library and place it in the "libraries" folder in arduino's installation path.
The RFID-MRC522 library requires the DigitalIO libraru to work.
