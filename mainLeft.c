//*************************************************************************/
/******Auther   : George Ayman Sedky                                     */
/******Date     : 7/12/2020                                            */
/******Version  : V1.0                                                 */
/*********************************************************************/
//LEFT MCU 2

#include <util/delay.h>
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "DIO_LIB/DIO_Interface.h"
#include "LCD_LIB/LCD_Init.h"
#include "LCD_LIB/LCD_Config.h"

#include "EXIT/EXIT_Init.h"



#define SWITCH_ON		0
#define SWITCH_OFF		1

#define Right 			1
#define Left			0
#define Ball			2
#define UP				0
#define DOWN			1

u8 RP_UP_DOWN=UP;
u8 result=0;
u8 flag=0;
void PrintPaddle_Result()
{
	LCD_VoidSendCmd(LCD_CLEAR);
	_delay_ms(10);
	LCD_VoidGoToXY(1, RP_UP_DOWN); //for left Screen MCU1
	LCD_VoidSendChar(Left);
	LCD_VoidGoToXY(0,0);
	LCD_VoidSendNum(result);
}
void PrintBall(u8 x, u8 y)
{
	LCD_VoidGoToXY(x,y);
	LCD_VoidSendChar(Ball);
}
void __vector_1()
{
	flag=1;
}

void __vector_2()
{
	result++;
}

void main (void)
{
	DIO_VoidSetPinDirection(PORTD,PIN0,OUTPUT);	//PD0 output
	DIO_VoidSetPinValue(PORTD,PIN0,LOW);		//PD0 -> 0 At First
	DIO_VoidSetPinDirection(PORTD,PIN4,OUTPUT);	//PD4 output
	DIO_VoidSetPinValue(PORTD,PIN4,LOW);		//PD4 -> 0 At First
	DIO_VoidSetPinDirection(PORTD,PIN2,INPUT);	//PD2 Input for INT0
	DIO_VoidSetPinValue(PORTD,PIN2,HIGH);		//PUll-up Enable
	DIO_VoidSetPinDirection(PORTD,PIN3,INPUT);	//PD3 Input for INT1
	DIO_VoidSetPinValue(PORTD,PIN3,HIGH);		//PUll-up Enable
	DIO_VoidSetPinDirection(PORTD,PIN1,INPUT);	//PD1 Input for Button
	DIO_VoidSetPinValue(PORTD,PIN1,HIGH);		//PUll-up Enable

	LCD_VoidInit();

	LCD_VoidSendSpcial();
	LCD_VoidSendStr("HI Iti !");
	_delay_ms(100);
	LCD_VoidSendCmd(LCD_CLEAR);
	_delay_ms(10);
	PrintPaddle_Result();
	_delay_ms(100);
	u8 i=2;
	while(i<=16){
		PrintPaddle_Result();
		PrintBall(i,0);
		i++;
	}
	i=2;
	EXIT0_VidInit();
	DIO_VoidSetPinValue(PORTD,PIN0,HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(PORTD,PIN0,LOW);
	while(1)
	{

		if(flag==1)
		{
			s8 i=15;
				while(i>=2){
					PrintPaddle_Result();
					PrintBall(i,0);
					i--;
					if(DIO_U8GetPinValue(PORTD,PIN1)==SWITCH_ON)
					{
						while(DIO_U8GetPinValue(PORTD,PIN1)==SWITCH_ON);
						LCD_VoidSendCmd(LCD_CLEAR);
						_delay_ms(10);
						if(RP_UP_DOWN==UP)
						{
							RP_UP_DOWN=DOWN;
						}
						else
						{
							RP_UP_DOWN=UP;
						}
					}
				}
				i++;
				if(RP_UP_DOWN==DOWN)
				{
					DIO_VoidSetPinValue(PORTD,PIN4,HIGH);
					_delay_ms(1);
					DIO_VoidSetPinValue(PORTD,PIN4,LOW);
				}
				while(i<=15){
					PrintPaddle_Result();
					PrintBall(i,0);
					i++;
					_delay_ms(500);
					if(DIO_U8GetPinValue(PORTD,PIN1)==SWITCH_ON)
					{
						while(DIO_U8GetPinValue(PORTD,PIN1)==SWITCH_ON);
						LCD_VoidSendCmd(LCD_CLEAR);
						_delay_ms(10);
						if(RP_UP_DOWN==UP)
						{
							RP_UP_DOWN=DOWN;
						}
						else
						{
							RP_UP_DOWN=UP;
						}
					}
				}
				DIO_VoidSetPinValue(PORTD,PIN0,HIGH);
				_delay_ms(1);
				DIO_VoidSetPinValue(PORTD,PIN0,LOW);
				flag=0;
		}
		if(DIO_U8GetPinValue(PORTD,PIN1)==SWITCH_ON)
		{
			while(DIO_U8GetPinValue(PORTD,PIN1)==SWITCH_ON);
			LCD_VoidSendCmd(LCD_CLEAR);
			_delay_ms(10);
			if(RP_UP_DOWN==UP)
			{
				RP_UP_DOWN=DOWN;
			}
			else
			{
				RP_UP_DOWN=UP;
			}
			PrintPaddle_Result();
		}

	}
}


