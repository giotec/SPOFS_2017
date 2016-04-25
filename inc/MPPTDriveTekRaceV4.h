/*
 * MPPTDriveTekRaceV4.h
 *
 *  Created on: Apr 25, 2016
 *      Author: Stuff
 */

#ifndef MPPTDRIVETEKRACEV4_H_
#define MPPTDRIVETEKRACEV4_H_

class MPPTDriveTekRaceV4 : CANReceiver {
public:
	MPPTDriveTekRaceV4(uint16_t MPPTAddress);
	~MPPTDriveTekRaceV4();

	void CANReceive(CANPacket PktIn);
	void TimedCalculations(uint16_t MSecInterval);

	uint16_t getMPPTAddress() const { return _MPPTAddress; }
	uint32_t getBusVIn() const { return _BusVIn; }
	uint32_t getBusIIn() const { return _BusIIn; }
	uint32_t getBusVOut() const { return _BusVOut; }
	uint32_t getWatts() const { return _BusVIn * _BusIIn; }
	float getWattHrs() const { return _WattHrs; }
	uint32_t getTemperature() const { return _Temperature; }
	uint8_t getStatus() const { return _Status; }

private:
	const uint16_t _MPPTAddress;

	uint32_t _BusVIn;
	uint32_t _BusIIn;
	uint32_t _BusVOut;
	uint32_t _Temperature;
	uint8_t _Status;
	float _WattHrs;

	float _PeakBusW;
	float _PeakBusV;
	float _PeakBusI;
};

#endif /* MPPTDRIVETEKRACEV4_H_ */
