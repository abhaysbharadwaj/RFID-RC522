/**
* Read a RFID card using a mfrc522 reader on your Serial SPI interface.
* Script is based on the script of Miguel Balboa.
* 
This is the Source code for the MFRC522 RFID module.
The code is written by Abhay S Bharadwaj (abhaysbharadwaj@gmail.com) & Anirban Chowdhury.
the code follows CC license, check license.txt for more information.
All text above must be included in any redistribution.
---------------------------------------------------------------------------------------
* Pin layout:
SOFT_SPI_MISO_PIN = 5 ----- can be changed in the RFID.cpp file
SOFT_SPI_MOSI_PIN = 6 ----- can be changed in the RFID.cpp file
SOFT_SPI_SCK_PIN  = 7 ----- can be changed in the RFID.cpp file
SOFT_SPI_SS_PIN: Pin 8 ----- can be changed in the code below
SOFT_SPI_RST_PIN: Pin 4 ----- can be changed in the code below
---------------------------------------------------------------------------------------
The card number is read using software SPI interface.
The read value is stored as a string in a variable.
The stored value is then printed.
--------------------------------------------------------------------------------------*/

#include "RFID.h"
#include <DigitalIO.h> // our software SPI library

#define SS_PIN 8
#define RST_PIN 4
 
RFID rfid(SS_PIN, RST_PIN); //create an instance rfid for the class RFID

// varables to store data
String cardNum;
unsigned long RFID;

void setup()
{ 
  Serial.begin(9600);
  Serial.println("initilizing RFID...");
  rfid.init(); // initilize the RFID module
  Serial.println("start ");
}

void loop()
{
 readRfid();
 printRfid();
}

void readRfid()
{
  if (rfid.isCard())
  {
    if (rfid.readCardSerial())
    {
      for (int i=0; i<=4; i++)//card value: "xyz xyz xyz xyz xyz" (15 digits maximum; 5 pairs of xyz)hence 0<=i<=4 //
      {
        RFID = rfid.serNum[i];
        cardNum += RFID; // store RFID value into string "cardNum" and concatinate it with each iteration
      }
    }
  }
  rfid.halt();
}

void printRfid()
{
 if (cardNum != '\0')//if string cardNum is not empty, print the value
 {
    Serial.println("Card found");
    Serial.print("Cardnumber: ");
    Serial.println(cardNum);
    cardNum.remove(0);
   //This is an arduino function.
  //remove the stored value after printing. else the new card value that is read
  // will be concatinated with the previous string.
  delay(500); 
 }
}
