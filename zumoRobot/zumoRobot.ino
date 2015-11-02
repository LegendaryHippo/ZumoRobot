#include <ZumoBuzzer.h>
#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>

// HYMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM

const int M_RIGHT_CONTROL = 7;
const int M_LEFT_CONTROL = 8;
const int M_RIGHT_PWM = 9;
const int M_LEFT_PWM = 10;
//pin
const int LED_PIN = 13;

ZumoMotors motors;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);

  motors.setSpeeds(200, -200);
}

void loop() {
  // put your main code here, to run repeatedly:

}
