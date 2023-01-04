#include "TB6600.h"

tb6600::tb6600(){
    setEnable(false);
}

tb6600::tb6600(uint8_t step_pin, uint8_t dir_pin, uint8_t enable_pin,uint8_t micro_steps)
{
    stepPin = step_pin;
    directionPin = dir_pin;
    enablePin = enable_pin;
    microSteps = micro_steps;
    
    if(microSteps == 1){
        ppr = pprs[0];
    } else if(microSteps == 2){
        ppr = pprs[1];
    } else if(microSteps == 4){
        ppr = pprs[2];
    } else if(microSteps == 8){
        ppr = pprs[3];
    } else if(microSteps == 16){
        ppr = pprs[4];
    } else if(microSteps == 32){
        ppr = pprs[5];
    } else if(microSteps == 64){
        ppr = pprs[6];
    }

    pinMode(stepPin,OUTPUT);
    pinMode(enablePin,OUTPUT);
    pinMode(directionPin,OUTPUT);
    setEnable(false);

}

// drives the stepper one step - better than duplicating this code
//@param ms milliseconds
//@param pin pin numer on your board for step
void tb6600::stepper(uint16_t ms, uint8_t pin){
    digitalWrite(pin,HIGH);
    delayMicroseconds(ms);
    digitalWrite(pin,LOW);
    delayMicroseconds(ms);
}

// drives the stepper 1 step based on the microstepping setup
void tb6600::step(){
    if(microSteps == 1){
        //ppr 200
        stepper(500,stepPin);
    } else if(microSteps == 2){
        //ppr 400
        stepper(500,stepPin);
    } else if(microSteps == 4){
        //ppr 800
        stepper(500,stepPin);
    } else if(microSteps == 8){
        //ppr 1600
        stepper(500,stepPin);
    } else if(microSteps == 16){
        // ppr 3200
        stepper(500,stepPin);
    } else if(microSteps == 32){
        //ppr 6400
        stepper(500,stepPin);
    }
}

// drives the stepper N steps
void tb6600::step(int steps){
    for (int i = 0; i < steps; i++){
        step();
    }
}

// drives the stepper N revolutions and stops
//@param revolutions - number of complete turns for the stepper to do
//@param mulitplier - number of microsteps for the stepper to complete 1 full revolution
void tb6600::step(int revolutions, int multiplier){
    for (int i = 0; i < (revolutions*multiplier); i++){
        step();
    }
}

//@TODO setup to drive the stepper 1 revolution based on microstepping
void tb6600::revolutions(int revolutions){
    if(microSteps == 1){
        //ppr 200
        step(revolutions,200);
    } else if(microSteps == 2){
        //ppr 400
        step(revolutions,400);
    } else if(microSteps == 4){
        //ppr 800
        step(revolutions,800);
    } else if(microSteps == 8){
        //ppr 1600
        step(revolutions,1600);
    } else if(microSteps == 16){
        // ppr 3200
        step(revolutions,3200);
    } else if(microSteps == 32){
        //ppr 6400
        step(revolutions,6400);
    }
    //delay needed otherwise steps will be skipped when changing direction rapidly
    delay(10);
}

// enables and disables the stepper driver
void tb6600::setEnable(uint8_t status){
      if(status == true)
    digitalWrite(enablePin,LOW);
  else
    digitalWrite(enablePin,HIGH);
}

// sets the rotational drirection of the stepper
void tb6600::setDirection(uint8_t status){
      if(status == true)
    digitalWrite(directionPin,LOW);
  else
    digitalWrite(directionPin,HIGH);
}

//test method to run your motor(s) 
void tb6600::motorTest()
{
    if (microSteps == 1) {
        for(int a = 0; a < pprs[0]; a++)
        {
            stepper(500,stepPin);
        }
    } else if (microSteps == 2) {
        for(int b = 0; b < pprs[1]; b++)
        {
            stepper(500,stepPin);
        }
    } else if (microSteps == 4) {
        for(int c = 0; c < pprs[2]; c++)
        {
            stepper(500,stepPin);
        }
    } else if (microSteps == 8) {
        for(int d = 0; d < pprs[3]; d++)
        {
            stepper(500,stepPin);
        }
    } else if (microSteps == 16) {
        for(int e = 0; e < pprs[4]; e++)
        {
            stepper(500,stepPin);
        }
    } else if (microSteps == 32) {
        for(int f = 0; f < pprs[5]; f++)
        {
            stepper(500,stepPin);
        }
    }
}
