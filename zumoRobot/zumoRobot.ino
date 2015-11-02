#include <ZumoBuzzer.h>
#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>

<<<<<<< HEAD
const int LED_PIN = 13;

bool test = false;

const int MAX_SPEED = 400;

ZumoMotors motors;
ZumoReflectanceSensorArray refSensors;
=======
// HYMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM

const int M_RIGHT_CONTROL = 7;
const int M_LEFT_CONTROL = 8;
const int M_RIGHT_PWM = 9;
const int M_LEFT_PWM = 10;
<<<<<<< HEAD
//pin
const int LED_PIN = 13;

=======
>>>>>>> a5acef8c32ea5c267006f465b418d16f75ee4eff
>>>>>>> refs/remotes/origin/master

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
<<<<<<< HEAD
  //motors.setSpeeds(-400, 400);
  refSensors.init();
  Serial.begin(9600);
  calibrateRefSensor();


  


=======
>>>>>>> refs/remotes/origin/master
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int sensors[6];
  int position = refSensors.readLine(sensors);
  Serial.println(position);

}

void calibrateRefSensor() {
  for (int i = 0; i < 80; i++)
  {
    if ((i > 10 && i <= 30) || (i > 50 && i <= 70))
      motors.setSpeeds(-200, 200);
    else
      motors.setSpeeds(200, -200);
    refSensors.calibrate();

    // Since our counter runs to 80, the total delay will be
    // 80*20 = 1600 ms.
    delay(20);
  }
  motors.setSpeeds(0, 0);
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
