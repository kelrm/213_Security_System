#include "alarm.h"
//#include "lcd.h"
#include "sms.h"
#include "pir.h"
#include "rfid.h"
int trigger = 0; // True if alarm triggered, false if not triggered
int armed = 0; // True if armed, false if not armed
int disarmed = 0;
int flag = 0;

// Main file for alarm system
void setup() {
 //Run the setup functions for all the components
 //lcd();
 wifiSetup();
 sensorSetup();
 rfidSetup();
 alarmSetup();
// lcdSetup();
// lcdDisarmed();
Serial.println("System Disarmed");
}
void loop() {
 armed = scan();
 if (armed == 1)
 {
  Serial.println("Waiting 15 seconds before arming...");
  delay(15000);
  Serial.println("System Armed");
 }
 while (armed == 1){
 int trigger = motionTrigger();
 if (trigger == 1){
  sendSMS();
  alarm();
  disarmed = scan();
  if (disarmed == 1){
    armed = 0;
    Serial.println("System Disarmed");
   break;
  }
 }
 }
}
