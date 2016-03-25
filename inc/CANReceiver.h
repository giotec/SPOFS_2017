#pragma once

#include "CANPacket.h"

class CANReceiver
{
public:
	CANReceiver();
	~CANReceiver();

	virtual void CANReceive(CANPacket PktIn) = 0;
};

