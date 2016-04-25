/*
 * MPPTDriveTekRaceV4.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: Stuff
 */

#include <MPPTDriveTekRaceV4.h>

MPPTDriveTekRaceV4::MPPTDriveTekRaceV4(uint16_t MPPTAddress):
_MPPTAddress(MPPTAddress)
{
	// TODO Auto-generated constructor stub

}

MPPTDriveTekRaceV4::~MPPTDriveTekRaceV4() {
	// TODO Auto-generated destructor stub
}

void MPPTDriveTekRaceV4::CANReceive(CANPacket PktIn)
{
	if (PktIn.GetCANID() == _MPPTAddress + 0x60)
	{
		uint32_t DataA = PktIn.GetDataA();
		uint32_t DataB = PktIn.GetDataB();


	}
}

void MPPTDriveTekRaceV4::TimedCalculations(uint16_t MSecInterval)
{

}
