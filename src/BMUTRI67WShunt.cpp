/*
 * BMU.cpp
 *
 *  Created on: Jan 9, 2016
 *      Author: Stuff
 */

#include "BMUTRI67WShunt.h"
#include "Converter.h"

BMUTRI67WShunt::BMUTRI67WShunt(uint16_t BMUAddr, uint16_t ShuntAddr):
_BMUAddress(BMUAddr),
_ShuntAddress(ShuntAddr)
{
	_BusI = 0;
	_BusV = 0;
	_ConnectionTimer = 3;
	_ShuntConnectionTimer = 3;
	_WattHrs = 0;
	_PeakBusV = 0;
	_PeakBusI = 0;
	_PeakBusW = 0;
	_Status = 0;
}

BMUTRI67WShunt::~BMUTRI67WShunt()
{
}

/**
@Parameters: CANPacket - Incoming packet object
@Return:	 Void

@Notes:		 Pass relevant CAN packets to this function for extraction
			 Unrecognized packets ignored
*/
void BMUTRI67WShunt::CANReceive(CANPacket PktIn)
{
	uint32_t CANID = PktIn.GetCANID();

	if (CANID == _ShuntAddress)
	{
		_BusV = conv_uint_float(PktIn.GetDataA()); // Values filtered on shunt side
		_BusI = conv_uint_float(PktIn.GetDataB());
		_ShuntConnectionTimer = 3;
		if (_PeakBusW < getWatts()) { _PeakBusW = getWatts(); }
		if (_PeakBusI < _BusI) { _PeakBusI = _BusI; }
		if (_PeakBusV < _BusV) { _PeakBusI = _BusV; }
	}
	else if (CANID == _ShuntAddress + 0x2)
	{
		_WattHrs = conv_uint_float(PktIn.GetDataA());
	}
	else if (CANID == _BMUAddress + 0xF8)
	{
		MinCellV = PktIn.GetDataA() & 0xFFFF;
		MaxCellV = (PktIn.GetDataA() >> 16) & 0xFFFF;
		CMUMinV = PktIn.GetDataB() & 0xFF;
		CMUMaxV = (PktIn.GetDataB() >> 16) & 0xFF;
		CellMinV = (PktIn.GetDataB() >> 8) & 0xFF;
		CellMaxV = (PktIn.GetDataB() >> 24) & 0xFF;
	}
	else if (CANID == _BMUAddress + 0xF9)
	{
		MinCellTmp = PktIn.GetDataA() & 0xFFFF;
		MaxCellTmp = (PktIn.GetDataA() >> 16) & 0xFFFF;
		CMUMinTmp = PktIn.GetDataB() & 0xFF;
		CMUMaxTmp = (PktIn.GetDataB() >> 16) & 0xFF;
	}
	else if (CANID == _BMUAddress + 0xFD)
	{
		_ConnectionTimer = 3;
		_Status = PktIn.GetDataA() & 0x7; // Only Voltage and Temperature flags relevant
	}
}

/**
@Parameters: MSecInterval - Milliseconds between calls to this function.
@Return:	 Void

@Notes:		 Call this function only inside a timed loop for consistent results
*/
void BMUTRI67WShunt::TimedCalculations(uint16_t MSecInterval)
{
	static int SecCounter = 0;

	SecCounter = (SecCounter + 1) % (1000 / MSecInterval);

	if (!SecCounter) { _ConnectionTimer--; }
}
