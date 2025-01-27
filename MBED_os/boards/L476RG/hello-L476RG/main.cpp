#include "mbed.h" 

DigitalOut led(LED1); 


int main(){ 

	while (1) { 
		led = !led; 
		thread_sleep_for(50); 
	} 
}