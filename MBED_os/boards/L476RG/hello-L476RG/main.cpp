/*  
 *  Structure of a main file for embedded project @ LEnsE
 *      Robotics Project / Ultrasound distance sensor
 *
 *  This code allows to get the distance from an ultrasound sensor. 
 *****************************************************************
 *  Pinout :
 *      PB_5 - Output - US trig input 
 *      PB_3 - Input - US echo output 
 *****************************************************************
 *  Tested with Nucleo XnnnMM board / Mbed OS 6
 *****************************************************************
 *  Author : J. VILLEMEJANE / LEnsE - Creation 2025/01/18
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