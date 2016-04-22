/*
 * Button.h
 *
 *  Created on: Dec 18, 2015
 *      Author: Stuff
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "LPC17xx.h"

class Button {
public:
  Button(uint8_t group, uint8_t bit);
  ~Button();

  enum ButtonStatus { UP = 0, DOWN = 1, RELEASED = 2, PRESSED = 4 };

  uint8_t GetBit() { return _GPIOBit; }
  uint8_t GetGroup() { return _GPIOGroup; }

  ButtonStatus UpdateStatus();
  ButtonStatus GetStatus() { return _Status; }
  
private:
  ButtonStatus _Status;
  const uint8_t _GPIOBit;
  const uint8_t _GPIOGroup;
};

#endif /* BUTTON_H_ */
