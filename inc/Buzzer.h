/*
 * Buzzer.h
 *
 *  Created on: Apr 10, 2016
 *      Author: Stuff
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "LPC17xx.h"

class Buzzer {
public:
	Buzzer(uint8_t Group, uint8_t Bit);
	~Buzzer();

	void OnMs(unsigned int MSec);
	void On();
	void Off();

	void SetActive(uint8_t Active) { _Active = Active > 0 ? 1 : 0; }
	uint8_t GetActive() { return _Active; }

	void TimedCalculations(uint16_t MSecInterval);

private:
	uint8_t _Active;
	uint16_t _Timer;
	const uint8_t _GPIOBit;
	const uint8_t _GPIOGroup;
};

#endif /* BUZZER_H_ */
