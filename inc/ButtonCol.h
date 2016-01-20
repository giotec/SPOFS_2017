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
  ButtonCollection(uint8_t** Btns, unsigned int BtnCount);
  virtual ~ButtonCollection();

  uint8_t *UpdateStatus();
  uint8_t *GetStatus();

private:
	unsigned int ButtonCount;
	Button **Buttons;
};

#endif /* BUTTONCOL_H_ */
