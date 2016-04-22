/*
 * Buzzer.cpp
 *
 *  Created on: Apr 10, 2016
 *      Author: Stuff
 */

#include <Buzzer.h>

Buzzer::Buzzer(uint8_t Group, uint8_t Bit):
_GPIOBit(Bit),
_GPIOGroup(Group)
{
	_Active = 1;
	_Timer = 0;
}

Buzzer::~Buzzer() {
	// TODO Auto-generated destructor stub
}

void Buzzer::TimedCalculations(uint16_t MSecInterval)
{
	if (_Timer >= MSecInterval)
	{
		_Timer -= MSecInterval;
	}
	else
	{
		_Timer = 0;
		Off();
	}
}

void Buzzer::OnMs(unsigned int MSec)
{
	if (_Active)
	{
		_Timer = MSec;
		On();
	}
}

void Buzzer::On()
{
	switch(_GPIOGroup)
	{
	default:
	case 0:
		LPC_GPIO0->FIOSET |= (1 << _GPIOBit);
		break;
	case 1:
		LPC_GPIO1->FIOSET |= (1 << _GPIOBit);
		break;
	case 2:
		LPC_GPIO2->FIOSET |= (1 << _GPIOBit);
		break;
	case 3:
		LPC_GPIO3->FIOSET |= (1 << _GPIOBit);
		break;
	case 4:
		LPC_GPIO4->FIOSET |= (1 << _GPIOBit);
		break;
	}
}

void Buzzer::Off()
{
	switch(_GPIOGroup)
	{
	default:
	case 0:
		LPC_GPIO0->FIOCLR |= (1 << _GPIOBit);
		break;
	case 1:
		LPC_GPIO1->FIOCLR |= (1 << _GPIOBit);
		break;
	case 2:
		LPC_GPIO2->FIOCLR |= (1 << _GPIOBit);
		break;
	case 3:
		LPC_GPIO3->FIOCLR |= (1 << _GPIOBit);
		break;
	case 4:
		LPC_GPIO4->FIOCLR |= (1 << _GPIOBit);
		break;
	}
}
