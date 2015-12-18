/*
 * ButtonGPIO1.cpp
 *
 *  Created on: Dec 18, 2015
 *      Author: Stuff
 */

#include "ButtonGPIO1.h"

ButtonGPIO1::ButtonGPIO1(int8_t bit)
: Button(bit)
{
  // TODO Auto-generated constructor stub
}

ButtonGPIO1::~ButtonGPIO1()
{
  // TODO Auto-generated destructor stub
}

/*
 * 0 - Up
 * 1 - Down
 * 2 - Released
 * 4 - Pressed
 */
int8_t ButtonGPIO1::UpdateStatus()
{
  int8_t _sts = LPC_GPIO1->FIOPIN & (1<<bit);

  switch(Status)
  {
    case UP:
      if (_sts) {Status = PRESSED;}
      else {Status = UP;}
      break;
    case DOWN:
      if (_sts) {Status = DOWN;}
      else {Status = RELEASED;}
      break;
    case RELEASED:
      if (_sts) {Status = PRESSED;}
      else {Status = UP;}
      break;
    case PRESSED:
      if (_sts) {Status = DOWN;}
      else {Status = RELEASED;}
      break;
    default:
      Status = UP;
      break;
  }

  return Status;
}
