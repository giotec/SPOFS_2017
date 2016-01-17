/*
 * Car.cpp
 *
 *  Created on: Jan 9, 2016
 *      Author: Stuff
 */

#include "Car.h"
#include "Clock.h"
#include "lpc17xx.h"

Car::Car()
{
  SystemInit();
  SystemCoreClockUpdate();

  // TODO: Init CAN objects

  Clk = new Clock();
}

Car::~Car()
{
  // TODO Auto-generated destructor stub
}

