#include "pins.h"
#include "intrins.h"

#define DELAY() \
    do {    \
        _nop_();_nop_();_nop_();_nop_(); \
    } while(0) \

void sn74hc595_send8bits(unsigned char content) {
    char i;
    for (i = 0; i < 8; i++) {
        SER = content & 0x01;
        content >>= 1;
        SRCLK = 0;
        DELAY();
        SRCLK = 1;
        DELAY();
    }
    RCLK = 0;
    DELAY();
    RCLK = 1;
    DELAY();
}

void sn74hc595_send16bits(unsigned int content) {
    char i;
    for (i = 0; i < 16; i++) {
        SER = content & 0x0001;
        content >>= 1;
        SRCLK = 0;
        DELAY();
        SRCLK = 1;
        DELAY();
    }
    RCLK = 0;
    DELAY();
    RCLK = 1;
    DELAY();
}

void led_display(char n, unsigned char content) {
    sn74hc595_send16bits((content << 8) | (1 << n));
}
