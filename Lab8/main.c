/**
 * main.c
 */

#include <inc/tm4c123gh6pm.h>
#include <stdbool.h>
#include "Timer.h"
#include "lcd.h"
#include <stdint.h>
#include "servo.h"

int main(void)
{
    timer_init();
    servo_init();

    printf("%d", servo_move(30));
}
