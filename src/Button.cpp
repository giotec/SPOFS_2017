/*
 * Button.cpp
 *
 *  Created on: Dec 18, 2015
 *      Author: Stuff
 */

#include "Button.h"

Button::Button(int8_t bit)
{
  GPIOBit = bit;
  Status = 0;
}

Button::~Button()
{
  // TODO Auto-generated destructor stub
}

int8_t Button::GetStatus()
{
  return Status;
}
