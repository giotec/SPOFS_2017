/*
 * Clock.h
 *
 *  Created on: Dec 19, 2015
 *      Author: Stuff
 */

#ifndef CLOCK_H_
#define CLOCK_H_

class Clock {
public:
  Clock();
  virtual ~Clock();

  void IncrementClock();
  int8_t IntervalCheck(Intervals _int);

  enum Intervals {IQSec, IHSec, ISec, IMin};

private:
  uint8_t   MSec;   // (mS / 10)
  uint8_t   Sec;
  uint8_t   Min;
  uint8_t   Hour;
  uint32_t  Days;
  uint8_t   Blink;  // half second toggle bit
};

#endif /* CLOCK_H_ */
