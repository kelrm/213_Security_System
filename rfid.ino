#include "rfid.h"
void rfidSetup() {
  Serial.println("Setting up RFID scannner...");
  Serial.begin(115200);// Initiate a serial communication
  delay(100);
  SPI.begin();// Initiate SPI bus
  delay(100);
  mfrc522.PCD_Init();// Initiate MFRC522
  delay(100);
  mfrc522.PCD_SetAntennaGain(mfrc522.RxGain_max);
  delay(300);
  Serial.println();
  delay(100);
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  displayColor(COLOR_BLACK);
}

int scan()
{
// Look for new cards
if ( ! mfrc522.PICC_IsNewCardPresent())
{
return 0;
}
// Select one of the cards
if ( ! mfrc522.PICC_ReadCardSerial())
{
return 0;
}
//Show UID on serial monitor
Serial.print("UID tag :");
String content= "";
byte letter;
for (byte i = 0; i < mfrc522.uid.size; i++)
{
Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
Serial.print(mfrc522.uid.uidByte[i], HEX);
content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
content.concat(String(mfrc522.uid.uidByte[i], HEX));
}
Serial.println();
content.toUpperCase();
//if (content.substring(1) == "19 DB 2B 2B") //change here the UID of the card/cards that you want to give access
if (content.substring(1) == "43 FA F0 0B") //change here the UID of the card/cards that you want to give access
{
Serial.println("Scanned allowed card");
delay(500);
displayColor(COLOR_BLUE);
delay(500);
displayColor(COLOR_GREEN);
delay(500);
displayColor(COLOR_BLACK);
return 1;
}

if (content.substring(1) != "43 FA F0 0B")
{
Serial.println("Scanned illegal card");
displayColor(COLOR_BLUE);
delay(500);
displayColor(COLOR_RED);
delay(500);
displayColor(COLOR_BLACK);
return 0;
}
}
void displayColor(byte color) {

digitalWrite(PIN_LED_R, !bitRead(color, 2));
digitalWrite(PIN_LED_G, !bitRead(color, 1));
digitalWrite(PIN_LED_B, !bitRead(color, 0));
}
