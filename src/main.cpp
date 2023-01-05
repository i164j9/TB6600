#include "TB6600.h"
/*
  NEMA17 stepper motors

  detent torque: 18mN.m REF
  rated voltage: 3.4VDC
  rated current: 1.0 amp
  Windinf inductance: 5.4x(1 +/- 20%)mH
  step angle: 1.8 deg +/- 0.09 deg
  max blank switching freq.: >= 2000pps 200khz
  rotational inertia: 4.32g.cm 2

*/
#define STEP        5
#define DIRECTION   4
#define ENABLE      6
/*
  pulses per rev:     200   400   800   1600    3200    6400
  DEGREES per step:   1.8,  .9,   .45,  .225,   .1125,  .05625
*/
#define MICROSTEP1    1   //ppr 200
#define MICROSTEP2    2   //ppr 400 - 2A/2B
#define MICROSTEP4    4   //ppr 800 
#define MICROSTEP8    8   //ppr 1600 
#define MICROSTEP16  16   //ppr 3200 
#define MICROSTEP32  32   //ppr 6400

tb6600 mot(STEP,DIRECTION,ENABLE,MICROSTEP1);

void setup()
{
  mot.setEnable(true);
}

//loop counter incremented each iteration
int counter = 0;

// run the motor below Nrevs
int target = 1;
int revs = 180;

void loop()
{
  //dependent on your motor wiring
  //false runs my steppers CCW
  mot.setDirection(true);
  
  // run steppers one full revolution CCW
  mot.revolutions(revs);
  delay(500);
  
  //true runs my steppers CW
  mot.setDirection(false);
  
  // run steppers one full revolution CW
  mot.revolutions(revs);
  
  counter++;

  if(counter == target)
  {
    mot.setEnable(false);
  }
  
}