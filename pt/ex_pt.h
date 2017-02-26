#ifndef __EX_PT_H_
#define __EX_PT_H_

#include "pt.h"

#define pt_state struct pt

#define pt_timestamp unsigned long

extern pt_timestamp systemTick;

#define PT_SYSTEMTICK systemTick

#define PT_DELAY(pt, ts, ticks)  \
	    do { \
    		ts = PT_SYSTEMTICK + ticks;   \
    		PT_WAIT_UNTIL(pt, ((PT_SYSTEMTICK) >= (ticks))); \
    	} while (0)

#define PT_TIMER_INIT(pt, timer) \
		timer = PT_SYSTEMTICK
			
#define PT_TIMER_SPIN(pt, timer, ticks) \
		do {  \
			timer += ticks; \
			PT_WAIT_UNTIL(pt, ((PT_SYSTEMTICK) >= (timer))); \
		} while (0)


#endif
