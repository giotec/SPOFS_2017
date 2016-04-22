/*
 * Light.cpp
 *
 *  Created on: Apr 10, 2016
 *      Author: Stuff
 */

#include <Light.h>

Light::Light(uint8_t group, uint8_t bit):
_GPIOBit(bit),
_GPIOGroup(group)
{
}

Light::~Light() {
	// TODO Auto-generated destructor stub
}

void Light::On()
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

void Light::Off()
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
