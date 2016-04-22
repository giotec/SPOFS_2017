#pragma once

#include "CANTransmitter.h"

// Manage Menu display functions into derived class (X : Menu) and call Menu constructor with menu counts in X constructor
// Track submenus in display functions (catch SubMenu -1 and default)
// Redefine CANSend in derived class

class Menu : CANTransmitter
{
protected:
	Menu(unsigned int TotalMenuCount, unsigned int ErrorCount, unsigned int ModeCount, unsigned int* ModeMenuCount);
	~Menu();

	virtual int CANSend(CANTransceiver *Interface, unsigned int PktID) = 0;
	virtual void DisplayMenu(void) = 0;
	virtual void DisplayError(uint8_t ErrorNo) = 0;

	void SetDriverMode(unsigned int Mode);
	unsigned int GetDriverMode() { return _Mode; }

	void SetMenuHome() { _CurrentSubMenuID = 0; _CurrentMenuID = 0; }
	void CycleMenu(int dir);
	void CycleSubMenu(int dir);

	void WriteTitle(char *Title);
	void WriteLine(char *String, unsigned int Line, unsigned int Pos, unsigned int Len);

	void RotateStringRight (char *String, unsigned int Len);
	void RotateStringLeft (char *String, unsigned int Len);

private:
	const unsigned int _TotalMenuCount;
	const unsigned int _ModeCount;
	const unsigned int _ModeMenuCount[];
	int _CurrentMenuID;
	int _CurrentSubMenuID;
	unsigned int _Mode;
};

