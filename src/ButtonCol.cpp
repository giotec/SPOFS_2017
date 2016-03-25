/*
 * ButtonCol.cpp
 *
 *  Created on: Dec 18, 2015
 *      Author: Stuff
 */

#include "ButtonCol.h"
#include "Button.h"

ButtonCollection::ButtonCollection(uint8_t* Btns[2], unsigned int BtnCount):ButtonCount(BtnCount)
{
	Buttons = new Button*[ButtonCount];

	for (int i = 0; i < ButtonCount; i++)
	{
		Buttons[i] = new Button(Btns[0][i], Btns[1][i]);
	}
}

ButtonCollection::~ButtonCollection()
{
	for (int i = 0; i < ButtonCount; i++)
	{
		delete Buttons[i];
	}
}

Button::ButtonStatus* ButtonCollection::GetStatus()
{
	Button::ButtonStatus *Status = new Button::ButtonStatus[ButtonCount];

	for (int i = 0; i < ButtonCount; i++)
	{
		Status[i] = Buttons[i]->GetStatus();
	}

	return Status;
}

Button::ButtonStatus* ButtonCollection::UpdateStatus()
{
	Button::ButtonStatus *Status = new Button::ButtonStatus[ButtonCount];

	for (int i = 0; i < ButtonCount; i++)
	{
		Status[i] = Buttons[i]->UpdateStatus();
	}

	return Status;
}

Button::ButtonStatus ButtonCollection::UpdateStatus(int btn)
{
	return Buttons[btn]->UpdateStatus();
}