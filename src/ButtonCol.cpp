/*
 * ButtonCol.cpp
 *
 *  Created on: Dec 18, 2015
 *      Author: Stuff
 */

#include "ButtonCol.h"
#include "Button.h"

ButtonCollection::ButtonCollection(uint8_t* Btns[2], unsigned int BtnCount)
{
	ButtonCount = BtnCount;

	Buttons = new Button*[ButtonCount];

	for (int i = 0; i < ButtonCount; i++)
	{
		Buttons[i] = new Button(Btns[0][i], Btns[1][i]);
	}
}

ButtonCollection::~ButtonCollection()
{
	// TODO Auto-generated destructor stub
}

uint8_t* ButtonCollection::GetStatus()
{
	uint8_t *Status = new uint8_t[ButtonCount];

	for (int i = 0; i < ButtonCount; i++)
	{
		Status[i] = Buttons[i]->GetStatus();
	}

	return Status;
}

uint8_t* ButtonCollection::UpdateStatus()
{
	uint8_t *Status = new uint8_t[ButtonCount];

	for (int i = 0; i < ButtonCount; i++)
	{
		Status[i] = Buttons[i]->UpdateStatus();
	}

	return Status;
}