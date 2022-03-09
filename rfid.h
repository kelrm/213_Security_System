#ifndef RFID_H
#define RFID_H
#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>
#include <SPI.h>

#define SS_PIN 23
#define RST_PIN 32
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.
const byte COLOR_BLACK = 0b111;
const byte COLOR_RED = 0b011;
const byte COLOR_GREEN = 0b110;
const byte COLOR_BLUE = 0b101;
const byte COLOR_MAGENTA = 0b010;
const byte COLOR_CYAN = 0b100;
const byte COLOR_YELLOW = 0b001;
const byte COLOR_WHITE = 0b000;

const byte PIN_LED_R = 15;
const byte PIN_LED_G = 27;
const byte PIN_LED_B = 33;

void rfidSetup();
int scan(); // Returns 0 if access denied, 1 if access granted
void displayColor(byte color);
#endif
