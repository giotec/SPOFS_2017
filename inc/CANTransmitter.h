#pragma once

#include "CANTransceiver.h"

class CANTransmitter
{
public:
	CANTransmitter();
	~CANTransmitter();

	virtual int CANSend(CANTransceiver *Interface, unsigned int PktID) = 0;
};

