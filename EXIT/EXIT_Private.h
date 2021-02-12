#ifndef _EXIT_PRIVATE_H
#define _EXIT_PRIVATE_H



#define MCUCR  *((volatile u8*)0x55)
#define GICR   *((volatile u8*)0x5B)
#define SREG   *((volatile u8*)0x5F)
#define MCUCSR *((volatile u8*)0x54)


void __vector_1() __attribute__((signal));
void __vector_2() __attribute__((signal));
void __vector_3() __attribute__((signal));
#endif
