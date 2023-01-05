/**
 * @file TB6600.h
 * @author Tom Miller (tom.tmiller@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-04
 * 
 * @copyright Copyleft (c) 2023
 * 
 *   This file is part of TB6600 Driver.
 *   TB6600 Driver is free software: you can redistribute it and/or modify it under
 *   the terms of the GNU General Public License as published by the Free Software
 *   Foundation, either version 3 of the License.
 *
 *   TB6600 Driver is distributed in the hope that it will be useful, but
 *   WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 *   Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License along
 *   with TB6600 Driver. If not, see <https://www.gnu.org/licenses/>. 
 */

#include "Arduino.h"

class tb6600{
    
    int stepPin;
    uint8_t directionPin;
    uint8_t enablePin;
    uint8_t microSteps;
    int pprs[6] = {200,400,800,1600,3200,6400};
    int ppr;
    
    void stepper(int, uint8_t);
    public:
        tb6600();
        tb6600(uint8_t, uint8_t, uint8_t,uint8_t);
        void step();
        void step(int);
        void step(int, int);
        void setEnable(uint8_t);
        void setDirection(uint8_t);
        void revolutions(int);
        void motorTest();
};
