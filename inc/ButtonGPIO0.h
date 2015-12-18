/*
 * ButtonGPIO0.h
 *
 *  Created on: Dec 18, 2015
 *      Author: Stuff
 */

#ifndef BUTTONGPIO0_H_
#define BUTTONGPIO0_H_

#include <Button.h>

class ButtonGPIO0: public Button {
public:
  ButtonGPIO0(int8_t bit);
  virtual ~ButtonGPIO0();
  int8_t UpdateStatus();
};

#endif /* BUTTONGPIO0_H_ */
