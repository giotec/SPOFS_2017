/*
 * ButtonGPIO3.h
 *
 *  Created on: Dec 18, 2015
 *      Author: Stuff
 */

#ifndef BUTTONGPIO3_H_
#define BUTTONGPIO3_H_

#include <Button.h>

class ButtonGPIO3: public Button {
public:
  ButtonGPIO3(int8_t bit);
  virtual ~ButtonGPIO3();
  int8_t UpdateStatus();
};

#endif /* BUTTONGPIO3_H_ */
