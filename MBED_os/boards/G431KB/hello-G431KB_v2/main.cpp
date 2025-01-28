/*  
 *  Structure of a main file for embedded project @ LEnsE
 *      Blinky on G431KB
 *
 *  This code allows to get the distance from an ultrasound sensor. 
 *****************************************************************
 *  Pinout :
 *      LED1 - LD2 on Nucleo-G431KB
 *****************************************************************
 *  Tested with Nucleo G431KB board / Mbed OS 6
 *****************************************************************
 *  Author : J. VILLEMEJANE / LEnsE - Creation 2025/01/28
 *****************************************************************
 *  LEnsE / https://lense.institutoptique.fr/
 *      Based on Mbed OS 6 example : mbed-os-example-blinky-baremetal
 */

#include "mbed.h"

DigitalOut  led1(LED1);

int main()
{
		printf("Hello G431KB - LEnsE !!\r\n");

    while(1)
    {
				led1 = !led1;
        thread_sleep_for(400);
    }
}