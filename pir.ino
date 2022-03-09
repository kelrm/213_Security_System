#include "pir.h"
int val = 0;                 // variable to store the sensor status
void sensorSetup() {
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(115200);       
  Serial.println("PIR sensor warming up...");
  delay(3); // Let the PIR sensor warm up for 30 seconds 30000
}

int motionTrigger(){
  val = digitalRead(sensor);   // read sensor value 
    if (val == HIGH)
      Serial.println("Motion detected!"); 
  return val;
}
