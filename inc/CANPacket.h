#pragma once

#include <stdint.h>

class CANPacket
{
public:
	CANPacket(uint32_t Frame, uint32_t CANID, uint32_t DataA, uint32_t DataB);
	~CANPacket();

	uint32_t GetFrame() { return _Frame; }
	uint32_t GetCANID() { return _CANID; }
	uint32_t GetDataA() { return _DataA; }
	uint32_t GetDataB() { return _DataB; }

private:
	const uint32_t _Frame;
	const uint32_t _CANID;
	const uint32_t _DataA;
	const uint32_t _DataB;
	//uint32_t TxCount;
	//uint32_t RxCount;
	//uint16_t ErrCount;
};

