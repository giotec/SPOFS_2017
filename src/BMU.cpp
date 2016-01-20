/*
 * BMU.cpp
 *
 *  Created on: Jan 9, 2016
 *      Author: Stuff
 */

#include "BMU.h"
#include "Converter.h"

BMU::BMU(uint16_t BMUAddr, uint16_t ShuntAddr):BMUAddress(BMUAddr),ShuntAddress(ShuntAddr)
{

}

BMU::~BMU()
{
  // TODO Auto-generated destructor stub
}

/**
@Parameters: Addr  - CAN Address of the packet received
			 DataA - Lower 32 bits of packet
			 DataB - Upper 32 bits of packet
@Return:	 Void

@Notes:		 Pass relevant CAN packets to this function for extraction
*/
void BMU::CANHandler(uint16_t Addr, uint32_t DataA, uint32_t DataB)
{
	if (Addr == ShuntAddress)
	{
		BusV = conv_uint_float(DataA); // Values filtered on shunt side
		BusI = conv_uint_float(DataB);
		ConnectionTimer = 3;
		if (PeakBusW < getWatts()) { PeakBusW = getWatts(); }
		if (PeakBusI < BusI) { PeakBusI = BusI; }
		if (PeakBusV < BusV) { PeakBusI = BusV; }
	}
	else if (Addr == ShuntAddress + 0x2)
	{
		WattHrs = conv_uint_float(DataA);
	}
	else if (Addr == BMUAddress + 0xF8)
	{
		MinCellV = DataA & 0xFFFF;
		MaxCellV = (DataA >> 16) & 0xFFFF;
		CMUMinV = DataB & 0xFF;
		CMUMaxV = (DataB >> 16) & 0xFF;
		CellMinV = (DataB >> 8) & 0xFF;
		CellMaxV = (DataB >> 24) & 0xFF;
	}
	else if (Addr == BMUAddress + 0xF9)
	{
		MinCellTmp = DataA & 0xFFFF;
		MaxCellTmp = (DataA >> 16) & 0xFFFF;
		CMUMinTmp = DataB & 0xFF;
		CMUMaxTmp = (DataB >> 16) & 0xFF;
	}
	else if (Addr == BMUAddress + 0xFD)
	{
		Status = DataA & 0x7; // Only Voltage and Temperature flags relevant
	}
}

/**
@Parameters: MSecInterval - Miliseconds between calls to this function.
@Return:	 Void

@Notes:		 Call this function only inside a timed loop for consistent results
*/
void BMU::TimedCalculations(uint16_t MSecInterval)
{
	static int SecCounter = 0;

	SecCounter = (SecCounter++) % (1000 / MSecInterval);

	if (!SecCounter) { ConnectionTimer--; }
}