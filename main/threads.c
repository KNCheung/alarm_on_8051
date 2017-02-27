#include "pt/ex_pt.h"
#include "drivers/SN74HC595.h"
#include "drivers/peripherals.h"
#include "apps/apps.h"

pt_state pt_blink;

char thread_blink(pt_state *pt) {
    static pt_timestamp timer;
    char isOn;

    PT_BEGIN(pt);

    PT_TIMER_INIT(pt, timer);
    while (1) {
        isOn = !isOn;
        led_display(5, (isOn?0xFE:0xFF));

        led_topleft_trigger();
			
        PT_TIMER_SPIN(pt, timer, 500);
    }
    PT_END(pt);
}

void threads_init(void) {
    PT_INIT(&pt_blink);
    apps_init();
}

void threads_loop(void) {
    while(1) {
        thread_blink(&pt_blink);
        apps_spin();
    }
}
