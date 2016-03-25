#pragma once

#include "CANPacket.h"
#include "LPC17xx.h"

class CANTransceiver
{
public:
	CANTransceiver(int Interface, uint32_t _BTR);
	~CANTransceiver();

	int Send(CANPacket PktOut);
	CANPacket Receive();

private:
	int Init(int Interface, uint32_t _BTR);
	
	LPC_CAN_TypeDef *_Interface;
	uint32_t _BTR;
};

