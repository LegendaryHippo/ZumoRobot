#include <ZumoBuzzer.h>
#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>

const int M_RIGHT_CONTROL = 7;
const int M_LEFT_CONTROL = 8;
const int M_RIGHT_PWM = 9;
const int M_LEFT_PWM = 10;
//pin
const int LED_PIN = 13;

const int MAX_SPEED = 400;

ZumoMotors motors;
ZumoReflectanceSensorArray refSensors;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  refSensors.init();
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, HIGH);
  motors.setSpeeds(400, -400);
}
