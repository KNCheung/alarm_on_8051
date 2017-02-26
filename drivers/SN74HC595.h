#ifndef __SN74HC595_H_
#define __SN74HC595_H_

void sn74hc595_send8bits(unsigned char content);
void sn74hc595_send16bits(unsigned int content);

void led_display(char n, unsigned char content);

#endif
