/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "timer.h"
#include "../led/led.h"

/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
extern unsigned char led_value;					/* defined in funct_led								*/
extern unsigned int IntCount;
extern unsigned int X;
extern unsigned int timer3_value;
void TIMER0_IRQHandler (void)
{
	static uint8_t position = 7;
	static uint8_t sw_count = 0;
	sw_count++;	
	if(sw_count == 10){
		LED_Off(position);
		if(position == 7)
			position = 2;
		else
			position++;
		LED_On(position);
		sw_count = 0;
	}
	/* alternatively to LED_On and LED_off try to use LED_Out */
	//LED_Out((1<<position)|(led_value & 0x3));							
	/* LED_Out is CRITICAL due to the shared led_value variable */
	/* LED_Out MUST NOT BE INTERRUPTED */
  LPC_TIM0->IR |= 1;			/* clear interrupt flag */
  return;
}


/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER1_IRQHandler (void)
{
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}

/* Timer 2 handler */
void TIMER2_IRQHandler (void)
{
	if(LPC_TIM3->TC == 0){
		IntCount++;
	}
	
	//disable_timer(2);
	//enable_timer(2);
	LPC_TIM2 -> TC = 0;
	//reset_timer(2);
	
  LPC_TIM2->IR = 1;			/* clear interrupt flag */
  return;
}

/* Timer 3 handler */
void TIMER3_IRQHandler (void)
{
	int i;
	
	reset_timer(3);
	
	LED_Out(0);
	
	//IntCount = 0;
	i = 0;
	while(i++ < X){
		__ASM("nop");
	}
	
	if(IntCount > 0x0000007F)
		LED_Out(0x000000FF);
	else
		LED_Out(IntCount);
	
	IntCount = 0;
	
	reset_timer(2);
	enable_timer(2);
	enable_timer(3);
	
  LPC_TIM3->IR = 1;			/* clear interrupt flag */
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
