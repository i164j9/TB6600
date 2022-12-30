# TB6600
A class for driving a TB6600 stepper driver<BR />
Working on adding more features as I need them for a project<BR />
this should be fairly self explainitory I will add example code in the near future.<BR />
TODO: add ability to enter degrees of rotation<BR />

pins on rfnano used here:<BR />
#define STEP        5<BR />
#define DIRECTION   4<BR />
#define ENABLE      6<BR />
#define MICROSTEP1  1   //ppr 200<BR />
#define MICROSTEP2  2   //ppr 400 - 2A/2B<BR />
#define MICROSTEP3  4   //ppr 800<BR />
#define MICROSTEP4  8   //ppr 1600<BR />
#define MICROSTEP5  16  //ppr 3200<BR />
#define MICROSTEP6  32  //ppr 6400<BR />
<BR />
tb6600 objName(STEP,DIRECTION,ENABLE,MICROSTEP3);<BR />

