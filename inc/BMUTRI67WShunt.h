/*
 * BMU.h
 *
 *  Created on: Jan 9, 2016
 *      Author: Stuff
 */

#ifndef BMUTRI67WSHUNT_H_
#define BMUTRI67WSHUNT_H_

#include "CommonDefs.h"
#include "CANReceiver.h"
#include "LPC17xx.h"

class BMUTRI67WShunt : CANReceiver {
public:
	BMUTRI67WShunt(uint16_t BMUAddr, uint16_t ShuntAddr);
	~BMUTRI67WShunt();

	void CANReceive(CANPacket PktIn);
	void TimedCalculations(uint16_t MSecInterval);

	uint16_t getBMUAddress() const { return _BMUAddress; }
	uint16_t getShuntAddress() const { return _ShuntAddress; }
	float getBusI() const { return _BusI; }
	float getBusV() const { return _BusV; }
	float getWatts() const { return _BusV * _BusI; }
	float getWattHrs() const { return _WattHrs; }
	uint32_t getStatus() const { return _Status | (_ConnectionTimer << 16); }

private:
	const uint16_t _BMUAddress;
	const uint16_t _ShuntAddress;
	uint8_t _ConnectionTimer;
	uint32_t _Status;

	float _BusV;
	float _BusI;
	float _WattHrs;

	float _PeakBusV;
	float _PeakBusI;
	float _PeakBusW;

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

#endif /* BMUTRI67WSHUNT_H_ */
