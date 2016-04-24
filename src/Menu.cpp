#include "Menu.h"
#include "lcd.h"


Menu::Menu(unsigned int TotalMenuCount, unsigned int ErrorCount, unsigned int ModeCount, unsigned int* ModeMenuCount) :
_TotalMenuCount(TotalMenuCount),
_ModeCount(ModeCount),
_ModeMenuCount(ModeMenuCount)
{
	this->_Menus = new void*[TotalMenuCount];
	this->_Errors = new void*[ErrorCount];
}


Menu::~Menu()
{
	delete _Menus;
	delete _Errors;
}

int Menu::CANSend(CANTransceiver * Interface, unsigned int PktID)
{
	return -1;
}

void Menu::CycleMenu(int dir)
{
	_CurrentSubMenuID = 0;
	_CurrentMenuID = (_CurrentMenuID + _ModeMenuCount[_Mode] + dir) % _ModeMenuCount[_Mode];
}

void Menu::CycleSubMenu(int dir)
{
	_CurrentSubMenuID = (_CurrentSubMenuID + dir);
}

void Menu::SetDriverMode(unsigned int Mode)
{
	MenuHome();
	if (Mode >= _ModeCount || Mode < 0) {_Mode = 0; return;}
	_Mode = Mode;
}

void Menu::WriteTitle(char* Title)
{
	lcd_putTitle(Title);
}

void Menu::WriteLine(char* String, unsigned int Line, unsigned int Pos, unsigned int Len = 20)
{
	lcp_putstring_custom((unsigned char) Line, (unsigned char) Pos, String, Len);
}

void Menu::RotateStringRight (char *String, unsigned int Len)
{
	char _Last = *(String + Len - 1);
	char* _Cur = (String + Len - 1);
	while (_Cur != String) {*_Cur = *(_Cur + 1); _Cur--;}
	*String = _Last;
}

void Menu::RotateStringLeft (char *String, unsigned int Len)
{
	char _First = *String;
	char* _Cur = String;
	while (_Cur != (String + Len - 1)) {*_Cur = *(_Cur + 1); _Cur++;}
	*(String + Len - 1) = _First;
}
