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
}

Clock::~Clock()
{
  // TODO Auto-generated destructor stub
}

int Clock::IncrementClock()
{
  MSec++;

  if(MSec >= 100) // Calculate time
  {
    MSec = 0;
    Sec++;
    if(Sec >= 60){Sec = 0;Min++;
    if(Min >= 60){Min = 0;Hour++;
    if(Hour >= 24){Hour = 0;Days++;}}}
  }

  // Add timed fire event checks here
  // ie every second or every 500mS set a return bit to be passed back to SysTick
  return 0;
}

uint8_t Clock::ToggleCheck(unsigned int _int)
{
  switch (_int)
  {
    case IQSec: // true for alternating quarter seconds
      return (MSec%50)/25;
      break;
    case IHSec: // true for alternating half seconds
      return MSec/50;
      break;
    case ISec: // true for alternating seconds
      return Sec%2;
      break;
    case IMin: // true for alternating minutes
      return Min%2;
      break;
    default:
      return 0;
      break;
  }
}
