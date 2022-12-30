#include "TB6600.h"

#define STEP        5
#define DIRECTION   4
#define ENABLE      6
#define MICROSTEP1  1   //ppr 200
#define MICROSTEP2  2   //ppr 400 - 2A/2B
#define MICROSTEP3  4   //ppr 800
#define MICROSTEP4  8   //ppr 1600
#define MICROSTEP5  16  //ppr 3200
#define MICROSTEP6  32  //ppr 6400

tb6600 mot(STEP,DIRECTION,ENABLE,MICROSTEP3);

void setup() {
  mot.setEnable(true);
  mot.setDirection(false);
}
//loop counter incremented each iteration
int counter = 0;

// run the loop below 100 times
int target = 100;

void loop() {
  //dependent on your motor wiring
  
  //false runs my steppers CCW
  mot.setDirection(false);

  // run steppers one full revolution CCW
  mot.revolutions(1);

  //true runs my steppers CW
  mot.setDirection(true);
  
  // run steppers one full revolution CW
  mot.revolutions(1);
  
  if(counter == target)
  {
    mot.setEnable(false);
  }
  counter++;
}