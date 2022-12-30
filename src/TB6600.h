#include "Arduino.h"

class tb6600{
    
    int stepPin;
    uint8_t directionPin;
    uint8_t enablePin;
    uint8_t microSteps;

    public:
        tb6600();
        tb6600(uint8_t step_pin, uint8_t dir_pin, uint8_t enable_pin,uint8_t micro_steps);
        void stepper(uint16_t ms, uint8_t pin);
        void step();
        void step(int steps);
        void step(int steps, int multiplier);
        void setEnable(uint8_t status);
        void setDirection(uint8_t status);
        void revolutions(int rev);
        void motorTest();
};
