#include <RH_ASK.h>
#include <SPI.h> // Not used but needed to compile

RH_ASK driver;

int res;

void setup(){
    pinMode(3,OUTPUT);
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop(){
    uint8_t buf[12];
    uint8_t buflen = sizeof(buf);
    
    if (driver.recv(buf, &buflen)){ // Non-blocking
      int i;
      // Message with a good checksum received, dump it.
      //Serial.print("");
      Serial.println((char*)buf);
      char result[2];
      result[0]= buf[0];
      result[1]= buf[1];

      res = result[0] - '0';
      res = (res*10) + result[1] - '0';

      
      Serial.println((char*)res);
    }

    if (res > 20)
      {
        digitalWrite(3,HIGH);
      }else
      {
        digitalWrite(3,LOW);
      }
}
