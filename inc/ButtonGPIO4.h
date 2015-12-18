/*
 * ButtonGPIO4.h
 *
 *  Created on: Dec 18, 2015
 *      Author: Stuff
 */

#ifndef BUTTONGPIO4_H_
#define BUTTONGPIO4_H_

#include <Button.h>

class ButtonGPIO4: public Button {
public:
  ButtonGPIO4(int8_t bit);
  virtual ~ButtonGPIO4();
  int8_t UpdateStatus();
};

#endif /* BUTTONGPIO4_H_ */
