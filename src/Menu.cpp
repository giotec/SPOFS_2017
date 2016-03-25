#include "Menu.h"



Menu::Menu()
{
}


Menu::~Menu()
{
}

int Menu::CANSend(CANTransceiver * Interface, unsigned int PktID)
{
	return 0;
}

void Menu::CycleMenu(int dir)
{
	_CurrentMenuID = (_CurrentMenuID + _MenuCount + dir) % _MenuCount;
}

void Menu::CycleSubMenu(int dir)
{
	_CurrentSubMenuID = (_CurrentSubMenuID + dir);
}

void Menu::SetDriverMode(unsigned int Mode)
{
}
