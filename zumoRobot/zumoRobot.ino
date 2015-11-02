#include <ZumoBuzzer.h>
#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>

bool test = false;

const int MAX_SPEED = 400;

unsigned int sensor_values[6];

ZumoMotors motors;
ZumoReflectanceSensorArray refSensors;

const int M_RIGHT_CONTROL = 7;
const int M_LEFT_CONTROL = 8;
const int M_RIGHT_PWM = 9;
const int M_LEFT_PWM = 10;
const int LED_PIN = 13;

int mSpeed = 50;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  refSensors.init();
  Serial.begin(9600);
  calibrateRefSensor();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int position = refSensors.readLine(sensor_values);
  //Serial.println(position);
  //followLine();

  refSensors.read(sensor_values);
  Serial.print(sensor_values[0]);
  Serial.print(" | ");
  Serial.println(sensor_values[5]);

}


//sensor 0= linje til venstre 2000=på linje 5000=linje til høyre
void followLine() {
  unsigned int sensors[6];
  int position = refSensors.readLine(sensors);
  Serial.println(position);

  if (2000 == position) {
    motors.setSpeeds(200, 200);
  }

  else if (2000 >= position) {
    motors.setSpeeds(-200, 200);
  }

  else if (2000 <= position) {
    motors.setSpeeds(200, -200);
  }

  delay(10);
}

//kalibrerer ref sensor i starten av programmet
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
