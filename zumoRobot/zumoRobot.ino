#include <ZumoBuzzer.h>
#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>

const int LED_PIN = 13;

bool test = false;

const int MAX_SPEED = 400;

ZumoMotors motors;
ZumoReflectanceSensorArray refSensors;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  refSensors.init();
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

}


void motorTest() {
  if (test == false) {
    motors.setSpeeds(-400, 400);
    test = true;
  }
  else {
    motors.setSpeeds(400, -400);
    test = false;
  }

  delay(1000);
  Serial.println(test);
}
