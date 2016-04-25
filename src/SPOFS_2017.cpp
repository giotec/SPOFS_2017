/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include "CANPacket.h"
#include "Car.h"
// TODO: insert other include files here

// TODO: insert other definitions and declarations here

// TODO: implement average power base class. Use static member to hold counter, protected access to individual figure.
// static reset function + get and set of individual figures.

Car* _Car;

int main(void) {

    // TODO: insert code here

	_Car = new Car(0x600, 0x530, 0x400, 0x716, 0x719, 0x500, 0x520, 0x510);

    while(1) {
        _Car->FreeRun();
    }
    return 0 ;
}

#ifdef __cplusplus
extern "C" {
#endif

	void SysTick_Handler(void)
	{
		_Car->TimedRun();
	}

	void CAN_IRQHandler(void)
	{
		uint32_t CANStatus = LPC_CANCR->CANRxSR;
		if ( CANStatus & (1 << 8) )
		{
			CANPacket Pkt(LPC_CAN1->RFS, LPC_CAN1->RID, LPC_CAN1->RDA, LPC_CAN1->RDB);
			_Car->CANReceive(Pkt);
			LPC_CAN1->CMR = 0x4;
		}
		else if ( CANStatus & (1 << 9) )
		{
			CANPacket Pkt(LPC_CAN2->RFS, LPC_CAN2->RID, LPC_CAN2->RDA, LPC_CAN2->RDB);
			_Car->CANReceive(Pkt);
			LPC_CAN2->CMR = 0x4;
		}
	}

#ifdef __cplusplus
}
#endif
