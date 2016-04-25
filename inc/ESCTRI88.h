/*
 * ESCTRI88.h
 *
 *  Created on: Apr 13, 2016
 *      Author: Stuff
 */

#ifndef ESCTRI88_H_
#define ESCTRI88_H_

#include "CommonDefs.h"
#include "CANReceiver.h"
#include "LPC17xx.h"

class ESCTRI88 : CANReceiver {
public:
	ESCTRI88(uint16_t ESCAddr);
	~ESCTRI88();

	void CANReceive(CANPacket PktIn);
	void TimedCalculations(uint16_t MSecInterval);

	uint16_t getESCAddress() const { return _ESCAddress; }
	float getBusI() const { return _BusI; }
	float getBusV() const { return _BusV; }
	float getWatts() const { return _BusV * _BusI; }
	float getWattHrs() const { return _WattHrs; }
	float getKMH() const { return _KMH; }
	float getOdometer() const { return _Odometer; }
	uint32_t getStatus() const { return _Status; }
	uint8_t getConnectionTimer() const { return _ConnectionTimer; }
	uint8_t isConnected() const { return _ConnectionTimer ? 1 : 0; }

private:
	const uint16_t _ESCAddress;
	uint8_t _ConnectionTimer;
	uint32_t _Status;

	float _BusV;
	float _BusI;
	float _WattHrs;

	float _PeakBusV;
	float _PeakBusI;
	float _PeakBusW;

	float _KMH;
	float _Odometer;

	float _MotorTemp;
};

#endif /* ESCTRI88_H_ */
