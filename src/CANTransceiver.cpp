#include "CANTransceiver.h"
#include "LPC17xx.h"

CANTransceiver::CANTransceiver(int Interface, uint32_t _BTR)
{
	if (Interface == 1)
	{
		_Interface = LPC_CAN1;
	}
	else
	{
		_Interface = LPC_CAN2;
	}

	Init(Interface, _BTR);
}


CANTransceiver::~CANTransceiver()
{
}

int CANTransceiver::Init(int Interface, uint32_t _BTR)
{
	if (Interface == 1)
	{
		LPC_SC->PCONP |= (1 << 13);  /* Enable CAN1 clock */

		LPC_PINCON->PINSEL1 |= (1 << 13) | (1 << 12) | (1 << 11) | (1 << 10);
	}
	else
	{
		LPC_SC->PCONP |= (1 << 14);  /* Enable CAN2 clock */

		LPC_PINCON->PINSEL0 |= (1 << 9) | (1 << 11);
	}

	_Interface->MOD = 1;    /* Reset CAN */
	_Interface->IER = 0;    /* Disable Receive Interrupt */
	_Interface->GSR = 0;    /* Reset error counter when CANxMOD is in reset	*/

	_Interface->BTR = _BTR;
	_Interface->MOD = 0x0;  /* CAN in normal operation mode */

	NVIC_EnableIRQ(CAN_IRQn);

	_Interface->IER = 0x01; /* Enable receive interrupts */
	return(1);
}

int CANTransceiver::Send(CANPacket PktOut)
{
	uint32_t CANStatus;

	//CAN1TxCount++;
	CANStatus = _Interface->SR;
	if (CANStatus & 0x00000004)
	{
		_Interface->TFI1 = PktOut.GetFrame() & 0xC00F0000;
		_Interface->TID1 = PktOut.GetCANID();
		_Interface->TDA1 = PktOut.GetDataA();
		_Interface->TDB1 = PktOut.GetDataB();
		_Interface->CMR |= 0x21;
		return (1);
	}
	else if (CANStatus & 0x00000400)
	{
		_Interface->TFI2 = PktOut.GetFrame() & 0xC00F0000;
		_Interface->TID2 = PktOut.GetCANID();
		_Interface->TDA2 = PktOut.GetDataA();
		_Interface->TDB2 = PktOut.GetDataB();
		_Interface->CMR |= 0x41;
		return (1);
	}
	else if (CANStatus & 0x00040000)
	{
		_Interface->TFI3 = PktOut.GetFrame() & 0xC00F0000;
		_Interface->TID3 = PktOut.GetCANID();
		_Interface->TDA3 = PktOut.GetDataA();
		_Interface->TDB3 = PktOut.GetDataB();
		_Interface->CMR |= 0x81;
		return (1);
	}
	return (0);
}

CANPacket CANTransceiver::Receive()
{
	return CANPacket(_Interface->RFS, _Interface->RID, _Interface->RDA, _Interface->RDB);
}

