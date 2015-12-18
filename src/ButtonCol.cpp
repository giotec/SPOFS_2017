/*
 * ButtonCol.cpp
 *
 *  Created on: Dec 18, 2015
 *      Author: Stuff
 */

#include "ButtonCol.h"
#include "ButtonGPIO0.h"
#include "ButtonGPIO1.h"
#include "ButtonGPIO2.h"
#include "ButtonGPIO3.h"
#include "ButtonGPIO4.h"

ButtonCol::ButtonCol(int8_t* Btns[2], unsigned int ButtonCount)
{
  // TODO Auto-generated constructor stub
  Buttons = new Button*[ButtonCount];

  for (int i = 0; i < ButtonCount; i++)
  {
    switch (Btns[0][i])
    {
      case 0:
        Buttons[i] = new ButtonGPIO0(Btns[1][i]);
        break;
      case 1:
        Buttons[i] = new ButtonGPIO1(Btns[1][i]);
        break;
      case 2:
        Buttons[i] = new ButtonGPIO2(Btns[1][i]);
        break;
      case 3:
        Buttons[i] = new ButtonGPIO3(Btns[1][i]);
        break;
      case 4:
        Buttons[i] = new ButtonGPIO4(Btns[1][i]);
        break;
      default:
        break;
    }
  }
}

ButtonCol::~ButtonCol()
{
  // TODO Auto-generated destructor stub
}
