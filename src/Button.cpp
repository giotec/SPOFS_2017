/*
 * Button.cpp
 *
 *  Created on: Dec 18, 2015
 *      Author: Stuff
 */

#include "Button.h"

Button::Button(uint8_t group, uint8_t bit):
_GPIOBit(bit),
_GPIOGroup(group)
{
  _Status = UP;
  switch (_GPIOGroup)
  	{
  	default:
  	case 0:
  		LPC_GPIO0->FIODIR &= ~(uint32_t)(1 << _GPIOBit);
  		break;
  	case 1:
  		LPC_GPIO1->FIODIR &= ~(uint32_t)(1 << _GPIOBit);
  		break;
  	case 2:
  		LPC_GPIO2->FIODIR &= ~(uint32_t)(1 << _GPIOBit);
  		break;
  	case 3:
  		LPC_GPIO3->FIODIR &= ~(uint32_t)(1 << _GPIOBit);
  		break;
  	case 4:
  		LPC_GPIO4->FIODIR &= ~(uint32_t)(1 << _GPIOBit);
  		break;
  	}
}

Button::~Button()
{
  // TODO Auto-generated destructor stub
}

Button::ButtonStatus Button::UpdateStatus()
{
	uint8_t _sts;
	switch (_GPIOGroup)
	{
	default:
	case 0:
		_sts = !LPC_GPIO0->FIOPIN & (1 << _GPIOBit);
		break;
	case 1:
		_sts = !LPC_GPIO1->FIOPIN & (1 << _GPIOBit);
		break;
	case 2:
		_sts = !LPC_GPIO2->FIOPIN & (1 << _GPIOBit);
		break;
	case 3:
		_sts = !LPC_GPIO3->FIOPIN & (1 << _GPIOBit);
		break;
	case 4:
		_sts = !LPC_GPIO4->FIOPIN & (1 << _GPIOBit);
		break;
	}

	switch (_Status)
	{
	case UP:
		if (_sts) { _Status = PRESSED; }
		else { _Status = UP; }
		break;
	case DOWN:
		if (_sts) { _Status = DOWN; }
		else { _Status = RELEASED; }
		break;
	case RELEASED:
		if (_sts) { _Status = PRESSED; }
		else { _Status = UP; }
		break;
	case PRESSED:
		if (_sts) { _Status = DOWN; }
		else { _Status = RELEASED; }
		break;
	default:
		_Status = UP;
		break;
	}

	return _Status;
}
