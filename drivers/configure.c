#include "pins.h"

void timer0_init(void) {  // 250us @ 12MHz
	AUXR &= 0x7F;
	TMOD &= 0xF0;
	TMOD |= 0x02;
	TL0 = 0x06;
	TH0 = 0x06;
	TF0 = 0;
	TR0 = 1;
}

void uart0_init(void)	//115200bps@12.000MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x40;		//定时器1时钟为Fosc,即1T
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设定定时器1为16位自动重装方式
	TL1 = 0xE6;		//设定定时初值
	TH1 = 0xFF;		//设定定时初值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
}

void interrupt_init(void) {
	ET0 = 1;
	EA = 1;
}

void pins_init(void) {
    // Switches
	P0M1 = 0xE0;
	P0M0 = 0xFC;
	P0 = 0x00;
	
	P2M1 = 0xFF;
	P2M0 = 0x00;
	P2 = 0xFF;
	
	P3M1 &= 0xFB;
	P3M0 |= 0x04;
	BUZZER = 0;
}

void peripherals_init(void) {
	pins_init();
	timer0_init();
	uart0_init();
	interrupt_init();
}
