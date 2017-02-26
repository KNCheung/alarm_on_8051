#include "STC15F2K60S2.h"
#include "pins.h"
#include "ex_pt.h"

void led_topleft_on(void) {
	PIN_LED_TOP_LEFT = 1;
}

void led_topleft_off(void) {
	PIN_LED_TOP_LEFT = 0;
}

void led_topleft_trigger(void) {
	PIN_LED_TOP_LEFT = !PIN_LED_TOP_LEFT;
}


unsigned long systemTick = 0;
void timer0_handler(void) interrupt 1 using 1{
	static unsigned char t0_cnt;
	EA = 0;
	t0_cnt++;
	if (!(t0_cnt & 0x03))
		systemTick++;
	EA = 1;   
}

void mcu_reset(void) {
    IAP_CONTR = 0x60;
    while (1);
}
