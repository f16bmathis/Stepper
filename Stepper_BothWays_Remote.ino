//  Remote makes motor go both ways, Button A
//  UNO, DM542T, POT, 
//  DMT wires, pins 8,9,10,11 to PUL+, PUL-, DIR+, DIR-
//  Remote through resistor to A1




#include <Stepper.h>
#define bt_F A1 // Go Button

const int stepsPerRevolution = 1600;  // 1 revolution value
const int analogInPin = A0;
int rotationCW = 0;
int rotationCCW = 0;
int location = 1;

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup()  {
  pinMode(bt_F, INPUT_PULLUP); // declare bt_F as input
  myStepper.setSpeed(200);  //Higher # is faster (5 to 1000?)

  Serial.begin(9600);
  }

void loop() {

  if (digitalRead (bt_F) == 0 && location == 1)
  {
    rotationCW = (20 * stepsPerRevolution);  //20 revolutions for linear slide

    myStepper.step(rotationCW);
    location = (2);
    Serial.println(location);
    delay(1000);
  }
 
    else if (digitalRead (bt_F) == 0 && location == 2)
{
    rotationCCW = (20 * -stepsPerRevolution);  //-20 to go back

    myStepper.step(rotationCCW);
    location = (1);
    Serial.println(location);
    delay(500);
}
 }
