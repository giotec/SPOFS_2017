#pragma once

#include "CANTransmitter.h"

#define	MAX_MENU_ITEMS 16
#define ERROR_ITEMS 4

class Menu : CANTransmitter
{
public:
	Menu();
	~Menu();

	int CANSend(CANTransceiver *Interface, unsigned int PktID);

	void CycleMenu(int dir);
	void CycleSubMenu(int dir);
	void DisplayMenu(int ac, double *av[]);
	void SetDriverMode(unsigned int Mode);

	// Insert Menu display functions below and call from DisplayMenu
	// Track submenus in display functions (catch SubMenu -1 and default)

private:
	int _CurrentMenuID;
	int _CurrentSubMenuID;
	unsigned int _MenuCount;
	unsigned int _Mode;
	void(*_Menus[MAX_MENU_ITEMS]) (int ac, double *av[]);
	void(*_Errors[ERROR_ITEMS]) (void);
};

