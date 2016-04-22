/*
 * ESCTRI88.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: Stuff
 */

#include <ESCTRI88.h>
#include "IIRFilter.h"

ESCTRI88::ESCTRI88(uint16_t ESCAddr) :
_ESCAddress(ESCAddr)
{
	_ConnectionTimer = 3;

	_BusV = 0;
	_BusI = 0;
	_WattHrs = 0;

	_PeakBusV = 0;
	_PeakBusI = 0;
	_PeakBusW = 0;

	_Odometer = 0;
	_KMH = 0;
}

ESCTRI88::~ESCTRI88() {}

/**
@Parameters: CANPacket - Incoming packet object
@Return:	 Void

@Notes:		 Pass relevant CAN packets to this function for extraction
			 Unrecognized packets ignored
*/
void ESCTRI88::CANReceive(CANPacket PktIn)
{
	_ConnectionTimer = 3;
	if (PktIn.GetCANID() == _ESCAddress + 1)
	{
		_Status = PktIn.GetDataA() >> 16;
	}
	else if (PktIn.GetCANID() == _ESCAddress + 2)
	{
		_BusV = iir_filter_float(conv_uint_float(PktIn.GetDataA()), _BusV, 1000);
		_BusI = iir_filter_float(conv_uint_float(PktIn.GetDataB()), _BusI, 1000);
		if (_PeakBusW < getWatts()) { _PeakBusW = getWatts(); }
		if (_PeakBusI < _BusI) { _PeakBusI = _BusI; }
		if (_PeakBusV < _BusV) { _PeakBusI = _BusV; }
	}
	else if (PktIn.GetCANID() == _ESCAddress + 3)
	{
		_KMH = conv_uint_float(PktIn.GetDataB()) * 3.6;
	}
	else if (PktIn.GetCANID() == _ESCAddress + 14)
	{
		_Odometer = conv_uint_float(PktIn.GetDataA());
	}
}

void ESCTRI88::TimedCalculations(uint16_t MSecInterval)
{
	static int SecCounter = 0;
	SecCounter = (SecCounter + 1) % (1000 / MSecInterval);
	if (!SecCounter) { _ConnectionTimer--; }

	_WattHrs += getWatts() / (3600000 / MSecInterval);
}
