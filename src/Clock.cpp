/*
 * Clock.cpp
 *
 *  Created on: Dec 19, 2015
 *      Author: Stuff
 */

#include "Clock.h"

Clock::Clock()
{
  MSec = 0;
  Sec = 0;
  Min = 0;
  Hour = 0;
  Days = 0;
  Blink = 0;
}

Clock::~Clock()
{
  // TODO Auto-generated destructor stub
}

void Clock::IncrementClock()
{
  MSec++;

  if(MSec/50){Blink = 1;}
  else{Blink = 0;}

  if(MSec >= 100) // Calculate time
  {
    MSec = 0;
    Sec++;
    if(Sec >= 60){Sec = 0;Min++;
    if(Min >= 60){Min = 0;Hour++;
    if(Hour >= 24){Hour = 0;Days++;}}}
  }
}

int8_t Clock::IntervalCheck(Intervals _int)
{
  switch (_int)
  {
    case IQSec:
      return MSec/25;
      break;
    case IHSec:
      return MSec/50;
      break;
    case ISec:
      break;
    case IMin:
      break;
    default:
      return 0;
      break;
  }
}
