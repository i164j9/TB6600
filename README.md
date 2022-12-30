# TB6600
A class for driving a TB6600 stepper driver
Working on adding more features as I need them for a project
this should be fairly self explainitory I will add example code in the near future.
TODO: add ability to enter degrees of rotation

pins on rfnano used here:
#define STEP        5
#define DIRECTION   4
#define ENABLE      6
#define MICROSTEP1  1   //ppr 200
#define MICROSTEP2  2   //ppr 400 - 2A/2B
#define MICROSTEP3  4   //ppr 800
#define MICROSTEP4  8   //ppr 1600
#define MICROSTEP5  16  //ppr 3200
#define MICROSTEP6  32  //ppr 6400

tb6600 objName(STEP,DIRECTION,ENABLE,MICROSTEP3);

