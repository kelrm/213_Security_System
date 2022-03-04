#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 23
#define RST_PIN 13
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
const byte COLOR_BLACK = 0b111;
const byte COLOR_RED = 0b011;
const byte COLOR_GREEN = 0b110;
const byte COLOR_BLUE = 0b101;
const byte COLOR_MAGENTA = 0b010;
const byte COLOR_CYAN = 0b100;
const byte COLOR_YELLOW = 0b001;
const byte COLOR_WHITE = 0b000;


const byte PIN_LED_R = 12;
const byte PIN_LED_G = 27;
const byte PIN_LED_B = 33;
 
void setup() 
{
  Serial.begin(115200);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  displayColor(COLOR_BLACK);

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
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
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "19 DB 2B 2B") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    delay(500);
    displayColor(COLOR_GREEN);
    delay(500);
    displayColor(COLOR_BLUE);
    delay(500);
    displayColor(COLOR_GREEN);
    delay(500);
    displayColor(COLOR_BLUE);
    delay(500);
    displayColor(COLOR_GREEN);
    delay(500);
  }
 
 else   {
    Serial.println("Access denied");
    delay(500);
    displayColor(COLOR_RED);
    delay(500);
    displayColor(COLOR_BLUE);
    delay(500);
    displayColor(COLOR_RED);
    delay(500);
    displayColor(COLOR_BLUE);
    delay(500);
    displayColor(COLOR_RED);
    delay(500);
  }
} 
void displayColor(byte color) {

  
  digitalWrite(PIN_LED_R, !bitRead(color, 2));
  digitalWrite(PIN_LED_G, !bitRead(color, 1));
  digitalWrite(PIN_LED_B, !bitRead(color, 0));
}
