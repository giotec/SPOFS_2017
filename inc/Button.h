/*
 * Button.h
 *
 *  Created on: Dec 18, 2015
 *      Author: Stuff
 */

#ifndef BUTTON_H_
#define BUTTON_H_



class Button {
public:
  Button(int8_t bit);
  virtual ~Button();
  virtual int8_t UpdateStatus() = 0;
  int8_t GetStatus();

protected:
  enum EStatus {UP = 0, DOWN = 1, RELEASED = 2, PRESSED = 4};
  EStatus Status;
  uint8_t GPIOBit;
};

#endif /* BUTTON_H_ */
