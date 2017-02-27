#include "STC15F2K60S2.h"
#include "pins.h"
#include "pt/ex_pt.h"

void led_topleft_on(void) {
	PIN_LED_TOP_LEFT = 1;
}

void led_topleft_off(void) {
	PIN_LED_TOP_LEFT = 0;
}

void led_topleft_trigger(void) {
	PIN_LED_TOP_LEFT = !PIN_LED_TOP_LEFT;
}

void led_topright_on(void) {
	PIN_LED_TOP_RIGHT = 1;
}

void led_topright_off(void) {
	PIN_LED_TOP_RIGHT = 0;
}

void led_topright_trigger(void) {
	PIN_LED_TOP_RIGHT = !PIN_LED_TOP_RIGHT;
}

void led_bottom_on(void) {
	PIN_LED_BOTTOM = 1;
}

void led_bottom_off(void) {
	PIN_LED_BOTTOM = 0;
}

void led_bottom_trigger(void) {
	PIN_LED_BOTTOM = !PIN_LED_BOTTOM;
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
