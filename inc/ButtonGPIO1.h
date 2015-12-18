/*
 * ButtonGPIO1.h
 *
 *  Created on: Dec 18, 2015
 *      Author: Stuff
 */

#ifndef BUTTONGPIO1_H_
#define BUTTONGPIO1_H_

#include <Button.h>

class ButtonGPIO1: public Button {
public:
  ButtonGPIO1(int8_t bit);
  virtual ~ButtonGPIO1();
  int8_t UpdateStatus();
};

#endif /* BUTTONGPIO1_H_ */
