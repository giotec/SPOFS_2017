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
#include "Car.h"
// TODO: insert other include files here

// TODO: insert other definitions and declarations here

Car* _Car;

int main(void) {

    // TODO: insert code here

	_Car = new Car(0x600, 0x530, 0x400, 0x716, 0x719, 0x500, 0x520, 0x510);

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
	// Replace with _Car.Run()
    while(1) {
        i++ ;
    }
    return 0 ;
}

#ifdef __cplusplus
extern "C" {
#endif

	void SysTick_Handler(void)
	{
		_Car->Clk->IncrementClock();
	}

	void CAN_IRQHandler(void)
	{

	}

#ifdef __cplusplus
}
#endif
