/*
 * ButtonCol.h
 *
 *  Created on: Dec 18, 2015
 *      Author: Stuff
 */

#include "LPC17xx.h"
#include "Button.h"

#ifndef BUTTONCOL_H_
#define BUTTONCOL_H_

class ButtonCollection {
public:
	ButtonCollection(uint8_t* Btns[2], unsigned int BtnCount);
	virtual ~ButtonCollection();

	Button::ButtonStatus *UpdateStatus();
	Button::ButtonStatus UpdateStatus(int btn);
	Button::ButtonStatus *GetStatus();

private:
	const unsigned int ButtonCount;
	Button **Buttons;
};

#endif /* BUTTONCOL_H_ */
