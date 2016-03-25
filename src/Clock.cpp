/*
 * Clock.cpp
 *
 *  Created on: Dec 19, 2015
 *      Author: Stuff
 */

#include "Clock.h"

Clock::Clock()
{
  _MSec = 0;
  _Sec = 0;
  _Min = 0;
  _Hour = 0;
  _Days = 0;
}

Clock::~Clock()
{
  // TODO Auto-generated destructor stub
}

int Clock::IncrementClock()
{
  _MSec++;

  if(_MSec >= 100) // Calculate time
  {
    _MSec = 0;
    _Sec++;
    if(_Sec >= 60){_Sec = 0;_Min++;
    if(_Min >= 60){_Min = 0;_Hour++;
    if(_Hour >= 24){_Hour = 0;_Days++;}}}
  }

  // Add timed fire event checks here
  // ie every second or every 500mS set a return bit to be passed back to SysTick
  return 0;
}

uint8_t Clock::ToggleCheck(Clock::Intervals _int)
{
  switch (_int)
  {
    case IQSec: // true for alternating quarter seconds
      return (_MSec%50)/25;
      break;
    case IHSec: // true for alternating half seconds
      return _MSec/50;
      break;
    case ISec: // true for alternating seconds
      return _Sec%2;
      break;
    case IMin: // true for alternating minutes
      return _Min%2;
      break;
    default:
      return 0;
      break;
  }
}
