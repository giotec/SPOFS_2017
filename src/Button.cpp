/*
 * Button.cpp
 *
 *  Created on: Dec 18, 2015
 *      Author: Stuff
 */

#include "Button.h"

Button::Button(uint8_t group, uint8_t bit)
{
  GPIOBit = bit;
  GPIOGroup = group;
  Status = UP;
}

Button::~Button()
{
  // TODO Auto-generated destructor stub
}

uint8_t Button::GetStatus()
{
  return Status;
}

uint8_t Button::UpdateStatus()
{
	uint8_t _sts;
	switch (GPIOGroup)
	{
	default:
	case 0:
		_sts = LPC_GPIO0->FIOPIN & (1 << GPIOBit);
		break;
	case 1:
		_sts = LPC_GPIO1->FIOPIN & (1 << GPIOBit);
		break;
	case 2:
		_sts = LPC_GPIO2->FIOPIN & (1 << GPIOBit);
		break;
	case 3:
		_sts = LPC_GPIO3->FIOPIN & (1 << GPIOBit);
		break;
	case 4:
		_sts = LPC_GPIO4->FIOPIN & (1 << GPIOBit);
		break;
	}

	switch (Status)
	{
	case UP:
		if (_sts) { Status = PRESSED; }
		else { Status = UP; }
		break;
	case DOWN:
		if (_sts) { Status = DOWN; }
		else { Status = RELEASED; }
		break;
	case RELEASED:
		if (_sts) { Status = PRESSED; }
		else { Status = UP; }
		break;
	case PRESSED:
		if (_sts) { Status = DOWN; }
		else { Status = RELEASED; }
		break;
	default:
		Status = UP;
		break;
	}

	return Status;
}

uint8_t Button::GetBit()
{
	return GPIOBit;
}

uint8_t Button::GetGroup()
{
	return GPIOGroup;
}