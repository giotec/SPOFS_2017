/*
 * Car.cpp
 *
 *  Created on: Jan 9, 2016
 *      Author: Stuff
 */

#include "Car.h"

Car::Car()
{
  SystemInit();
  SystemCoreClockUpdate();

  // Init all static variables to be loaded into classes
  uint8_t *_btns[2];
  _btns[0] = new uint8_t[5];
  _btns[1] = new uint8_t[5];
  _btns[0][0] = 0;_btns[1][0] = 0;
  _btns[0][1] = 0;_btns[1][1] = 1;
  _btns[0][2] = 0;_btns[1][2] = 3;
  _btns[0][3] = 0;_btns[1][3] = 6;
  _btns[0][4] = 0;_btns[1][4] = 7;

  // TODO: Init CAN objects

  Clk = new Clock();

  Btns = new ButtonCollection(_btns, 4);

  Bmu = new BMU((uint16_t)0x600, (uint16_t)0x530);
}

Car::~Car()
{
  // TODO Auto-generated destructor stub
}

