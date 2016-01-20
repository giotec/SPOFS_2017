/*
 * Car.h
 *
 *  Created on: Jan 9, 2016
 *      Author: Stuff
 */


#ifndef CAR_H_
#define CAR_H_

#include "Clock.h"
#include "ButtonCol.h"
#include "BMU.h"
#include "lpc17xx.h"

class Car {
public:
  Car();
  virtual ~Car();

  Clock *Clk;
  ButtonCollection *Btns;
  BMU *Bmu;
};

#endif /* CAR_H_ */
