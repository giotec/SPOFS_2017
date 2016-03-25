/*
 * Clock.h
 *
 *  Created on: Dec 19, 2015
 *      Author: Stuff
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include "LPC17xx.h"

class Clock {
public:
  Clock();
  virtual ~Clock();

  enum Intervals { IQSec, IHSec, ISec, IMin };

  int IncrementClock();
  uint8_t ToggleCheck(Clock::Intervals _int);

private:
  uint8_t   _MSec;   // (mS / 10)
  uint8_t   _Sec;
  uint8_t   _Min;
  uint8_t   _Hour;
  uint32_t  _Days;
};

#endif /* CLOCK_H_ */
