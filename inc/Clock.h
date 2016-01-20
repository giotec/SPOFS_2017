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

  int IncrementClock();
  uint8_t ToggleCheck(unsigned int _int);

  enum Intervals {IQSec, IHSec, ISec, IMin};

private:
  uint8_t   MSec;   // (mS / 10)
  uint8_t   Sec;
  uint8_t   Min;
  uint8_t   Hour;
  uint32_t  Days;
};

#endif /* CLOCK_H_ */
