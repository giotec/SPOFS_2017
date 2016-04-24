/*
 * Car.h
 *
 *  Created on: Jan 9, 2016
 *      Author: Stuff
 */


#ifndef CAR_H_
#define CAR_H_

#include "Clock.h"
#include "Button.h"
#include "Switch.h"
#include "BMUTRI67WShunt.h"
#include "ESCTRI88.h"
#include "Menu.h"
#include "Light.h"
#include "Buzzer.h"
#include "lpc17xx.h"

class Car : Menu {
public:
	Car(uint16_t MSecTick, uint16_t BmuAddr, uint16_t ShuntAddr, uint16_t MotorAddr, uint16_t MPPT1Addr, uint16_t MPPT2Addr, uint16_t ControlAddr, uint16_t InboundAddr, uint16_t OutboundAddr, unsigned int TotalMenuCount, unsigned int ErrorCount, unsigned int ModeCount, unsigned int* ModeMenuCount);
	~Car();

	// External Calls
	int FreeRun();
	int TimedRun();
	int CANReceive(CANPacket PktIn);

private:
	// Buttons
	Button *BtLeft;
	Button *BtRight;
	Button *BtUp;
	Button *BtDown;
	Button *BtSelect;

	Button *BtMechBrake;

	// Switches
	Switch *SwIndicators;
	Switch *SwHazards;
	Switch *SwDriveMode;
	Switch *SwDriveDirection;

	// Lights on Board
	Light *LgFault;
	Light *LgHV;
	Light *LgLeftBlinkerBoard;
	Light *LgRightBlinkerBoard;
	Light *LgReverse;
	Light *LgRegen;
	Light *LgNeutral;
	Light *LgDrive;
	Light *LgNormal;
	Light *LgRace;

	// Lights off Board
	Light *LgLeftBlinkerCar;
	Light *LgRightBlinkerCar;
	Light *LgBrake;

	// Other on Board
	Buzzer *Buzz;

	// Misc
	Clock *Clk;

	// Car Components
	BMUTRI67WShunt *Bmu;
	ESCTRI88 *Esc;
	
	// Menu
	int CANSend(CANTransceiver *Interface, unsigned int PktID);
	void DisplayMenu();
	void DisplayError(uint8_t ErrorNo);

	void MenuErrorOnStart();
	void MenuDriver();
	void MenuIntro();

	void MenuInfo();
	void MenuEscBus();
	void MenuHome();
	void MenuControls();
	void MenuCruise();
	void MenuMPPT1();
	void MenuMPPT2();
	void MenuMPPTPower();
	void MenuMotor();
	void MenuBattery();
	void MenuAveragePower();
	void MenuTemperature();
	void MenuDebug();
	void MenuConfig();
	void MenuErrors();
	void MenuOptions();
	void MenuPeaks();
	void MenuRuntime();
	void MenuOdometer();

	void MenuSWOC();
	void MenuHWOC();
	void MenuComms();
	void MenuBatteryError();

	const uint16_t _MSecTick;
	const uint16_t _BmuAddress;
	const uint16_t _ShuntAddress;
	const uint16_t _MotorAddress;
	const uint16_t _MPPT1Address;
	const uint16_t _MPPT2Address;
	const uint16_t _ControlAddress;
	const uint16_t _InboundAddress;
	const uint16_t _OutboundAddress;
};

#endif /* CAR_H_ */
