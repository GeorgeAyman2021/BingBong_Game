//*************************************************************************/
/******Auther   : George Ayman Sedky                                     */
/******Date     : 6/12/2020                                            */
/******Version  : V1.0                                                 */
/*********************************************************************/
#include "EXIT_Private.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../DIO_LIB/DIO_Interface.h"

#include <util/delay.h>



/*
void __vector_1()
{
	DIO_VoidTogglePin(PORTD,PIN0);
	_delay_ms(10);
}
*/
/*
void __vector_2()
{
	DIO_VoidTogglePin(PORTD,PIN0);
	_delay_ms(10);
}

*/
void __vector_3()
{
	DIO_VoidTogglePin(PORTD,PIN0);
	_delay_ms(10);
}



void GIE_Enable(void)
{
	//Enable Globale Interrput
	SET_BIT(SREG,7);    //I -> 1

}

void GIE_Disable(void)
{
	//Disable Globale Interrput
	CLR_BIT(SREG,7);    //I -> 0

}

void EXIT0_Enable(void)
{
	// PIE=Enable EXIT INT0
	SET_BIT(GICR,6) ;//INT0 ->1
}

void EXIT0_Disable(void)
{
	// PIE=Disable EXIT INT0
	CLR_BIT(GICR,6) ;//INT0 ->0
}

void EXIT1_Enable(void)
{
	// PIE=Enable EXIT INT1
	SET_BIT(GICR,7) ;//INT1 ->1
}

void EXIT1_Disable(void)
{
	// PIE=Disable EXIT INT1
	CLR_BIT(GICR,7) ;//INT1->0
}

void EXIT2_Enable(void)
{
	// PIE=Enable EXIT INT2
	SET_BIT(GICR,5) ;//INT2 ->1
}

void EXIT2_Disable(void)
{
	// PIE=Disable EXIT INT2
	CLR_BIT(GICR,5) ;//INT2 ->0
}

void EXIT0_VidInit(void)
{
	//ISC0=RISING Edge
	SET_BIT(MCUCR,1); //ISC11 ->1
	SET_BIT(MCUCR,0 );//ISC10 ->1

	//ISC1=RISING Edge
	SET_BIT(MCUCR,3); //ISC11 ->1
	SET_BIT(MCUCR,2 );//ISC10 ->1


	EXIT0_Enable();
	EXIT1_Enable();
	GIE_Enable();
}
