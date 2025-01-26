#include "mbed.h" 

DigitalOut led(LED1); 
AnalogIn		inAn(PA_0);

int val_adc = 0;

int main(){ 
	
	while(1){ 
		led = !led; 
		val_adc = inAn.read_u16();
		printf("Val = %d \r\n", val_adc);
		thread_sleep_for(500);
	} 
}