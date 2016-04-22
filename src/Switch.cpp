/*
 * Switch.cpp
 *
 *  Created on: Mar 30, 2016
 *      Author: Stuff
 */

#include <Switch.h>

Switch::Switch(uint8_t UpGroup, uint8_t UpBit, uint8_t DownGroup, uint8_t DownBit):
_GPIOUpGroup(UpGroup),
_GPIOUpBit(UpBit),
_GPIODownGroup(DownGroup),
_GPIODownBit(DownBit),
_ConnectionType(0)
{
	switch (_GPIOUpGroup)
	{
	default:
	case 0:
		LPC_GPIO0->FIODIR &= ~(uint32_t)(1 << _GPIOUpBit);
		break;
	case 1:
		LPC_GPIO1->FIODIR &= ~(uint32_t)(1 << _GPIOUpBit);
		break;
	case 2:
		LPC_GPIO2->FIODIR &= ~(uint32_t)(1 << _GPIOUpBit);
		break;
	case 3:
		LPC_GPIO3->FIODIR &= ~(uint32_t)(1 << _GPIOUpBit);
		break;
	case 4:
		LPC_GPIO4->FIODIR &= ~(uint32_t)(1 << _GPIOUpBit);
		break;
	}
	switch (_GPIODownGroup)
	{
	default:
	case 0:
		LPC_GPIO0->FIODIR &= ~(uint32_t)(1 << _GPIODownBit);
		break;
	case 1:
		LPC_GPIO1->FIODIR &= ~(uint32_t)(1 << _GPIODownBit);
		break;
	case 2:
		LPC_GPIO2->FIODIR &= ~(uint32_t)(1 << _GPIODownBit);
		break;
	case 3:
		LPC_GPIO3->FIODIR &= ~(uint32_t)(1 << _GPIODownBit);
		break;
	case 4:
		LPC_GPIO4->FIODIR &= ~(uint32_t)(1 << _GPIODownBit);
		break;
	}
}

Switch::Switch(uint8_t Group, uint8_t Bit):
_GPIOUpGroup(Group),
_GPIOUpBit(Bit),
_GPIODownGroup(0),
_GPIODownBit(0),
_ConnectionType(1)
{
	switch (_GPIOUpGroup)
	{
	default:
	case 0:
		LPC_GPIO0->FIODIR &= ~(uint32_t)(1 << _GPIOUpBit);
		break;
	case 1:
		LPC_GPIO1->FIODIR &= ~(uint32_t)(1 << _GPIOUpBit);
		break;
	case 2:
		LPC_GPIO2->FIODIR &= ~(uint32_t)(1 << _GPIOUpBit);
		break;
	case 3:
		LPC_GPIO3->FIODIR &= ~(uint32_t)(1 << _GPIOUpBit);
		break;
	case 4:
		LPC_GPIO4->FIODIR &= ~(uint32_t)(1 << _GPIOUpBit);
		break;
	}
}

Switch::~Switch() {
}

SwitchStatus Switch::UpdateStatus()
{
	uint8_t _UpSts, _DownSts;
	switch (_GPIOUpGroup)
	{
	default:
	case 0:
		_UpSts = !LPC_GPIO0->FIOPIN & (1 << _GPIOUpBit);
		break;
	case 1:
		_UpSts = !LPC_GPIO1->FIOPIN & (1 << _GPIOUpBit);
		break;
	case 2:
		_UpSts = !LPC_GPIO2->FIOPIN & (1 << _GPIOUpBit);
		break;
	case 3:
		_UpSts = !LPC_GPIO3->FIOPIN & (1 << _GPIOUpBit);
		break;
	case 4:
		_UpSts = !LPC_GPIO4->FIOPIN & (1 << _GPIOUpBit);
		break;
	}

	if (_ConnectionType)
	{
		switch (_GPIODownGroup)
		{
		default:
		case 0:
			_DownSts = !LPC_GPIO0->FIOPIN & (1 << _GPIODownBit);
			break;
		case 1:
			_DownSts = !LPC_GPIO1->FIOPIN & (1 << _GPIODownBit);
			break;
		case 2:
			_DownSts = !LPC_GPIO2->FIOPIN & (1 << _GPIODownBit);
			break;
		case 3:
			_DownSts = !LPC_GPIO3->FIOPIN & (1 << _GPIODownBit);
			break;
		case 4:
			_DownSts = !LPC_GPIO4->FIOPIN & (1 << _GPIODownBit);
			break;
		}
	}
	else {_DownSts = 0;}

	if (_UpSts || _Status == HELDUP)
	{
		if (!_UpSts && _Status == HELDUP) {_Status = RELEASEUP;}
		else {_Status = HELPUP;}
	}
	else if (_DownSts || _Status == HELDDOWN)
	{
		if (!_DownSts && _Status == HELDDOWN) {_Status == RELEASEDOWN;}
		else {_Status = HELDDOWN;}
	}
	else {_Status = CENTRED;}

	return _Status;
}
