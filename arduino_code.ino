// Defining Constant Variables
#include <Stepper.h>

const float STEPS_PER_REV = 400;
const float DEG_PER_STEP = 0.9;

// X is X
const int stepX = 2;
const int dirX  = 5;
const int stepsX = 400;
const int speedX = 1000;

// Y is Ro
const int stepY = 3;
const int dirY  = 6;
const int stepsY = 5;
const int speedY = 100;

// Z is Phi
const int stepZ = 4;
const int dirZ  = 7;
const int stepsZ = 5;
const int speedZ = 100;

const int enPin = 8;

Stepper stepperX(STEPS_PER_REV, stepX, dirX);
Stepper stepperY(STEPS_PER_REV, stepY, dirY);
Stepper stepperZ(STEPS_PER_REV, stepZ, dirZ);

void setup() {
  // Stepper Library Takes Care of Pins!
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  Serial.begin(9600);
}

void loop() {
  // Waiting for Python Serial Signal
  String buffer = "";
  while(Serial.available() >= 2)
  {
    for(int i=0;i<2;i++) {
      char c = Serial.read();
      buffer += c;
    }
    int action = buffer.toInt();
    switch (action) {
      case 0:
         stepperX.setSpeed(speedX);   
         stepperX.step(-stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(-stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(-stepsZ);
         break;
      case 1:
         stepperX.setSpeed(speedX);   
         stepperX.step(-stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(-stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(0);
         break;
      case 2:
         stepperX.setSpeed(speedX);   
         stepperX.step(-stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(-stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(stepsZ);
         break;
      case 3:
         stepperX.setSpeed(speedX);   
         stepperX.step(-stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(0);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(-stepsZ);
         break;
      case 4:
         stepperX.setSpeed(speedX);   
         stepperX.step(-stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(0);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(0);
         break;
      case 5:
         stepperX.setSpeed(speedX);   
         stepperX.step(-stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(-stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(stepsZ);
         break;
      case 6:
         stepperX.setSpeed(speedX);   
         stepperX.step(-stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(-stepsZ);
         break;
      case 7:
         stepperX.setSpeed(speedX);   
         stepperX.step(-stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(0);
         break;
      case 8:
         stepperX.setSpeed(speedX);   
         stepperX.step(-stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(stepsZ);
         break;
      case 9:
         stepperX.setSpeed(speedX);   
         stepperX.step(0);
         stepperY.setSpeed(speedY);   
         stepperY.step(-stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(-stepsZ);
         break;
      case 10:
         stepperX.setSpeed(speedX);   
         stepperX.step(0);
         stepperY.setSpeed(speedY);   
         stepperY.step(-stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(0);
         break;
      case 11:
         stepperX.setSpeed(speedX);   
         stepperX.step(0);
         stepperY.setSpeed(speedY);   
         stepperY.step(-stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(stepsZ);
         break;
      case 12:
         stepperX.setSpeed(speedX);   
         stepperX.step(0);
         stepperY.setSpeed(speedY);   
         stepperY.step(0);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(-stepsZ);
         break;
      case 13:
         stepperX.setSpeed(speedX);   
         stepperX.step(0);
         stepperY.setSpeed(speedY);   
         stepperY.step(0);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(0);
         break;
      case 14:
         stepperX.setSpeed(speedX);   
         stepperX.step(0);
         stepperY.setSpeed(speedY);   
         stepperY.step(0);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(stepsZ);
         break;
      case 15:
         stepperX.setSpeed(speedX);   
         stepperX.step(0);
         stepperY.setSpeed(speedY);   
         stepperY.step(stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(-stepsZ);
         break;
      case 16:
         stepperX.setSpeed(speedX);   
         stepperX.step(0);
         stepperY.setSpeed(speedY);   
         stepperY.step(stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(0);
         break;
      case 17:
         stepperX.setSpeed(speedX);   
         stepperX.step(0);
         stepperY.setSpeed(speedY);   
         stepperY.step(stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(stepsZ);
         break;
      case 18:
         stepperX.setSpeed(speedX);   
         stepperX.step(stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(-stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(-stepsZ);
         break;
      case 19:
         stepperX.setSpeed(speedX);   
         stepperX.step(stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(-stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(0);
         break;
      case 20:
         stepperX.setSpeed(speedX);   
         stepperX.step(stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(-stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(stepsZ);
         break;
      case 21:
         stepperX.setSpeed(speedX);   
         stepperX.step(stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(0);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(-stepsZ);
         break;
      case 22:
         stepperX.setSpeed(speedX);   
         stepperX.step(stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(0);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(0);
         break;
      case 23:
         stepperX.setSpeed(speedX);   
         stepperX.step(stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(0);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(stepsZ);
         break;
      case 24:
         stepperX.setSpeed(speedX);   
         stepperX.step(stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(-stepsZ);
         break;
      case 25:
         stepperX.setSpeed(speedX);   
         stepperX.step(stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(0);
         break;
      case 26:
         stepperX.setSpeed(speedX);   
         stepperX.step(stepsX);
         stepperY.setSpeed(speedY);   
         stepperY.step(stepsY);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(stepsZ);
         break;
      default:
         // Invalid input means no movement
         stepperX.setSpeed(speedX);   
         stepperX.step(0);
         stepperY.setSpeed(speedY);   
         stepperY.step(0);
         stepperZ.setSpeed(speedZ);   
         stepperZ.step(0);
         break;
    }
    delay(1000);
  }
}
