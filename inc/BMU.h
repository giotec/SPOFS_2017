/*
 * BMU.h
 *
 *  Created on: Jan 9, 2016
 *      Author: Stuff
 */

#ifndef BMU_H_
#define BMU_H_

class BMU {
public:
  BMU();
  virtual ~BMU();

  float getBusI() const {return BusI;}

  float getBusV() const {return BusV;}

  float getWattHrs() const {return WattHrs;}

private:
  float BusV;
  float BusI;
  float WattHrs;
};

#endif /* BMU_H_ */
