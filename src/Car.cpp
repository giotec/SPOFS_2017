/*
 * Car.cpp
 *
 *  Created on: Jan 9, 2016
 *      Author: Stuff
 */

#include "Car.h"

Car::Car(uint16_t MSecTick, uint16_t BmuAddr, uint16_t ShuntAddr, uint16_t MotorAddr, uint16_t MPPT1Addr, uint16_t MPPT2Addr, uint16_t ControlAddr, uint16_t InboundAddr, uint16_t OutboundAddr, unsigned int TotalMenuCount, unsigned int ErrorCount, unsigned int ModeCount, unsigned int* ModeMenuCount) :
Menu(TotalMenuCount, ErrorCount, ModeCount, ModeMenuCount),
_MSecTick(MSecTick),
_BmuAddress(BmuAddr),
_ShuntAddress(ShuntAddr),
_MotorAddress(MotorAddr),
_MPPT1Address(MPPT1Addr),
_MPPT2Address(MPPT2Addr),
_ControlAddress(ControlAddr),
_InboundAddress(InboundAddr),
_OutboundAddress(OutboundAddr)
{
	SystemInit();
	SystemCoreClockUpdate();

	// Init all static variables to be loaded into classes
	// TODO: Init CAN objects

	BtLeft   = new Button(1, 27);
	BtRight  = new Button(0, 0);
	BtUp     = new Button(0, 1);
	BtDown   = new Button(1, 28);
	BtSelect = new Button(1, 29);

	BtMechBrake = new Button(0, 25);

	SwIndicators     = new Switch(1, 1, 1, 0); // Up = Left, Down = Right
	SwHazards        = new Switch(2, 12, 2, 13);
	SwDriveMode      = new Switch(2, 11, 2, 10);
	SwDriveDirection = new Switch(0, 10, 0, 11);

	LgFault             = new Light(0, 27);
	LgHV                = new Light(1, 8);
	LgLeftBlinkerBoard  = new Light(3, 25);
	LgRightBlinkerBoard = new Light(3, 26);
	LgReverse           = new Light(1, 26);
	LgRegen             = new Light(1, 24);
	LgNeutral           = new Light(1, 25);
	LgDrive             = new Light(1, 23);
	LgNormal            = new Light(1, 30);
	LgRace              = new Light(1, 31);

	LgLeftBlinkerCar  = new Light(1, 20);
	LgRightBlinkerCar = new Light(1, 19);
	LgBrake           = new Light(1, 21);

	Buzz = new Buzzer(0, 3);

	Clk = new Clock();
	Can500K = new CANTransceiver(1, CANTransceiver.BitRate.BITRATE500K30MHZ);
	Can125K = new CANTransceiver(2, CANTransceiver.BitRate.BITRATE125K30MHZ);

	Bmu = new BMUTRI67WShunt(_BmuAddress, _ShuntAddress);
	Esc = new ESCTRI88(_MotorAddress);
	Mppt1 = new MPPTDriveTekRaceV4(_MPPT1Address);
	Mppt2 = new MPPTDriveTekRaceV4(_MPPT2Address);

	SysTick_Config(SystemCoreClock / (1000 / _MSecTick));
}

Car::~Car()
{
	delete Buzz;
	delete Clk;
	delete Can125K;
	delete Can500K;
	delete Bmu;
	delete Esc;
	delete Mppt1;
	delete Mppt2;

	// Buttons
	delete BtLeft;
	delete BtRight;
	delete BtUp;
	delete BtDown;
	delete BtSelect;

	// Switches
	delete SwIndicators;
	delete SwHazards;
	delete SwDriveMode;
	delete SwDriveDirection;

	// Lights on Board
	delete LgFault;
	delete LgHV;
	delete LgLeftBlinkerBoard;
	delete LgRightBlinkerBoard;
	delete LgReverse;
	delete LgRegen;
	delete LgNeutral;
	delete LgDrive;
	delete LgNormal;
	delete LgRace;

	// Lights off Board
	delete LgLeftBlinkerCar;
	delete LgRightBlinkerCar;
	delete LgBrake;
}

int Car::CANSend(CANTransceiver *Interface, CANPacket PktOut)
{
	return Interface->Send(PktOut);
}

int Car::FreeRun()
{
	return 0;
}

int Car::TimedRun()
{
	Clk->IncrementClock(_MSecTick);
	Bmu->TimedCalculations(_MSecTick);
	Buzz->TimedCalculations(_MSecTick);
	Esc->TimedCalculations(_MSecTick);
	return 0;
}

int Car::CANReceive(CANPacket PktIn)
{
	uint32_t CANID = PktIn.GetCANID();

	// BMU
	if (CANID == _BmuAddress   + 0xF8
	 || CANID == _BmuAddress   + 0xF9
	 || CANID == _BmuAddress   + 0xFD
	 || CANID == _ShuntAddress
	 || CANID == _ShuntAddress + 0x02)
	{ Bmu->CANReceive(PktIn); }
	// ESC
	else if (CANID == _MotorAddress + 0x01
		  || CANID == _MotorAddress + 0x02
		  || CANID == _MotorAddress + 0x03
		  || CANID == _MotorAddress + 0x0B
		  || CANID == _MotorAddress + 0x0E)
	{ Esc->CANReceive(PktIn); }
	// MPPTS -- receive and redirect packets onto main network for collection by telemetry
	else if (CANID == _MPPT1Address + 0x60)
	{
		Mppt1->CANReceive(PktIn);
		CANSend(Can500K, PktIn);
	}
	else if (CANID == _MPPT2Address + 0x60)
	{
		Mppt2->CANReceive(PktIn);
		CANSend(Can500K, PktIn);
	}
	// Other Packets
}
