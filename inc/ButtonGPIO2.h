/*
 * ButtonGPIO2.h
 *
 *  Created on: Dec 18, 2015
 *      Author: Stuff
 */

#ifndef BUTTONGPIO2_H_
#define BUTTONGPIO2_H_

#include <Button.h>

class ButtonGPIO2: public Button {
public:
  ButtonGPIO2(int8_t bit);
  virtual ~ButtonGPIO2();
  int8_t UpdateStatus();
};

#endif /* BUTTONGPIO2_H_ */
