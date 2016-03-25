/*
 * Car.cpp
 *
 *  Created on: Jan 9, 2016
 *      Author: Stuff
 */

#include "Car.h"

Car::Car(uint16_t BmuAddr, uint16_t ShuntAddr, uint16_t MotorAddr, uint16_t MPPT1Addr, uint16_t MPPT2Addr, uint16_t ControlAddr, uint16_t InboundAddr, uint16_t OutboundAddr) :
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
  /*
  uint8_t *_btns[2];
  _btns[0] = new uint8_t[5];
  _btns[1] = new uint8_t[5];
  _btns[0][0] = 0;_btns[1][0] = 0;
  _btns[0][1] = 0;_btns[1][1] = 1;
  _btns[0][2] = 0;_btns[1][2] = 3;
  _btns[0][3] = 0;_btns[1][3] = 6;
  _btns[0][4] = 0;_btns[1][4] = 7;
  */

  // TODO: Init CAN objects

  Left   = new Button(1, 27);
  Right  = new Button(0, 0);
  Up     = new Button(0, 1);
  Down   = new Button(1, 28);
  Select = new Button(1, 29);

  Clk = new Clock();

  //Btns = new ButtonCollection(_btns, sizeof(_btns[0]));

  Bmu = new BMU(_BmuAddress, _ShuntAddress);

  /*
  delete[] _btns[0];
  delete[] _btns[1];
  */
}

Car::~Car()
{
	delete Clk;
	//delete Btns;
	delete Bmu;

	delete Left;
	delete Right;
	delete Up;
	delete Down;
	delete Select;
}

