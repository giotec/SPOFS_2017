/*
 * Car.h
 *
 *  Created on: Jan 9, 2016
 *      Author: Stuff
 */


#ifndef CAR_H_
#define CAR_H_

#include "Clock.h"
//#include "ButtonCol.h"
#include "Button.h"
#include "BMU.h"
#include "Menu.h"
#include "lpc17xx.h"

class Car {
public:
	Car(uint16_t BmuAddr, uint16_t ShuntAddr, uint16_t MotorAddr, uint16_t MPPT1Addr, uint16_t MPPT2Addr, uint16_t ControlAddr, uint16_t InboundAddr, uint16_t OutboundAddr);
	virtual ~Car();

	// Buttons
	Button *Left;
	Button *Right;
	Button *Up;
	Button *Down;
	Button *Select;

	Clock *Clk;
	//ButtonCollection *Btns;
	BMU *Bmu;
	
private:
	const uint16_t _BmuAddress;
	const uint16_t _ShuntAddress;
	const uint16_t _MotorAddress;
	const uint16_t _MPPT1Address;
	const uint16_t _MPPT2Address;
	const uint16_t _ControlAddress;
	const uint16_t _InboundAddress;
	const uint16_t _OutboundAddress;

	Menu _Menu;
};

#endif /* CAR_H_ */
