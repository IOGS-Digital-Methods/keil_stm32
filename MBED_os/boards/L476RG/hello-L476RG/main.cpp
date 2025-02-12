/*  
 *  Structure of a main file for embedded project @ LEnsE
 *      Blinky on L476RG
 *
 *  This code allows to toggle the onboard LED at a period of 0.4s. 
 *****************************************************************
 *  Pinout :
 *      LED1 - LD2 on Nucleo-L476RG
 *****************************************************************
 *  Tested with Nucleo L476RG board / Mbed OS 6
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
		printf("Hello L476RG - LEnsE !!\r\n");

    while(1)
    {
				led1 = !led1;
        thread_sleep_for(400);
    }
}