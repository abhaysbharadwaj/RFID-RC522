# RFID-MRC522
This is the arduino code to read RFID card using MRC-522 RFID module.
The code used Software SPI pins. i.e. your SPI pins are not fixed, any pin of the arduino can be configured to act as any SPI pin.
The code uses DigitalIO library to make use of the Software SPI functionality.

# DigitalIO
The digitalIO library can be found at: https://github.com/greiman/DigitalIO
Download this library and place it in the "libraries" folder in arduino's installation path.
The RFID-MRC522 library requires the DigitalIO libraru to work.
