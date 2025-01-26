#include "mbed.h" 

DigitalOut led(LED1); 
AnalogIn		inAn(PA_0);
PwmOut			motor_L1(PA_4);

Ticker  tik;

void tik_tok(void){
	led = !led; 
}
	


int val_adc = 0;

int main(){ 
	motor_L1.period_ms(20);
	motor_L1.write(0.3);
	tik.attach(&tik_tok, 400ms);
	while(1){ 
		val_adc = inAn.read_u16();
		printf("Val = %d \r\n", val_adc);
		thread_sleep_for(500);
	} 
}