#include "CANPacket.h"



CANPacket::CANPacket(uint32_t Frame, uint32_t CANID, uint32_t DataA, uint32_t DataB) : _Frame(Frame), _CANID(CANID), _DataA(DataA), _DataB(DataB)
{

}


CANPacket::~CANPacket()
{
}
