/*
 * Switch.h
 *
 *  Created on: Mar 30, 2016
 *      Author: Stuff
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#include "LPC17xx.h"

class Switch {
public:
	Switch(uint8_t UpGroup, uint8_t UpBit, uint8_t DownGroup, uint8_t DownBit);
	Switch(uint8_t Group, uint8_t Bit);
	~Switch();

	enum SwitchStatus { CENTRED = 0, HELDUP = 1, HELDDOWN = 2, RELEASEUP = 4, RELEASEDOWN = 8 };

	uint8_t GetUpBit() { return _GPIOUpBit; }
	uint8_t GetUpGroup() { return _GPIOUpGroup; }
	uint8_t GetDownBit() { return _GPIODownBit; }
	uint8_t GetDownGroup() { return _GPIODownGroup; }

	SwitchStatus UpdateStatus();
	SwitchStatus GetStatus() { return _Status; }

private:
	SwitchStatus _Status;
	const uint8_t _ConnectionType; // 0 - Up and Down connected on different pins, 1 - Only Up connected to pin
	const uint8_t _GPIOUpBit;
	const uint8_t _GPIOUpGroup;
	const uint8_t _GPIODownBit;
	const uint8_t _GPIODownGroup;
};

#endif /* SWITCH_H_ */
