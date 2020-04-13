/*
 * servo.c
 *
 *  Created on: Apr 3, 2020
 *      Author: Seth Braddock
 */

#include "Timer.h"
#include "lcd.h"
#include <stdint.h>
#include "servo.h"

void servo_init()
{
    SYSCTL_RCGCGPIO_R |= 0x2; //Enables Clock for Port B

    GPIO_PORTB_DIR_R |= 0x20; //Set PB5 as output
    GPIO_PORTB_AFSEL_R |= 0x20; //Select Alternate Function on Port B pin 5
    GPIO_PORTB_PCTL_R |= 0x700000; //Disable Timers before configuring/Enable Alternate Function
    GPIO_PORTB_DEN_R |= 0x20; //Digital Enables for pin PB5

    TIMER1_CTL_R &= ~0x100; //Disable timer before editing
    TIMER1_CFG_R |= 0x4; //enable Timer 1B as 16-bit
    TIMER1_TBMR_R |= 0xA; //configure PWM for the timer
    TIMER1_CTL_R &= ~0x40; //make non-inverting

    //TIMER1_TBPR_R //Set 8-bit prescaler
    //TIMER1_TBILR_R //Set the start value
    //TIMER1_TBMATCHR_R //Set TnEn bit to enable timer and start counting

    TIMER1_CTL_R |= 0x100; //Start the timer
}

int servo_move(float degrees)
{
    return 0;
}

