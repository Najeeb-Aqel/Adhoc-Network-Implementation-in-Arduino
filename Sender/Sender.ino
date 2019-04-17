#include <RH_ASK.h>
#include <SPI.h> // Not used but needed to compile

RH_ASK driver;

const int tmpSensorPin = A0;
int reading;
float tmp;

void setup() {
  Serial.begin(9600);    // Debu#include <RH_ASK.h>
#include <SPI.h> // Not used but needed to compile

RH_ASK driver;

const int tmpSensorPin = A0;
int reading;
float tmp;

void setup() {
  Serial.begin(9600);    // Debugging only
  if (!driver.init())
    Serial.println("init failed");
}

void loop() {
  readTmp();
  char msg[20];
  dtostrf(tmp, 2 , 0 , msg);
  Serial.println(msg);
  //sprintf(msg,"tmp=%s,distance=%s",msg,msg);
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(1000);
}

void readTmp() {
  reading = analogRead(tmpSensorPin);
  tmp = (reading * 5.0 * 100 / 1023.0) - 50;
}
