/*
 * BMU.h
 *
 *  Created on: Jan 9, 2016
 *      Author: Stuff
 */

#ifndef BMU_H_
#define BMU_H_

#include "CommonDefs.h"
#include "LPC17xx.h"

class BMU {
public:
	BMU(uint16_t BMUAddr, uint16_t ShuntAddr);
	virtual ~BMU();

	void CANHandler(uint16_t Addr, uint32_t DataA, uint32_t DataB);
	void TimedCalculations(uint16_t MSecInterval);

	uint16_t getBMUAddress() const { return BMUAddress; }
	uint16_t getShuntAddress() const { return ShuntAddress; }
	float getBusI() const { return BusI; }
	float getBusV() const { return BusV; }
	float getWatts() const { return BusV * BusI; }
	float getWattHrs() const { return WattHrs; }
	uint32_t getStatus() const { return Status | (ConnectionTimer << 16); }

private:
	const uint16_t BMUAddress;
	const uint16_t ShuntAddress;
	uint8_t ConnectionTimer;
	uint32_t Status;

	float BusV;
	float BusI;
	float WattHrs;

	float PeakBusV;
	float PeakBusI;
	float PeakBusW;

	// These are probably unnessecary 
	uint16_t MinCellV;    // Minimum Cell Voltage
	uint16_t MaxCellV;    // Maximum Cell Voltage
	uint8_t CMUMinV;      // CMU number with minimum cell voltage
	uint8_t CMUMaxV;      // CMU number with maximum cell voltage
	uint8_t CellMinV;     // Cell number with minimum cell voltage
	uint8_t CellMaxV;	  // Cell number with maximum cell voltage

	uint16_t MinCellTmp;  // Minimum Cell Temperature
	uint16_t MaxCellTmp;  // Maximum Cell Temperature
	uint8_t CMUMinTmp;    // CMU number with minimum cell temperature
	uint8_t CMUMaxTmp;    // CMU number with maximum cell temperature
};

#endif /* BMU_H_ */
