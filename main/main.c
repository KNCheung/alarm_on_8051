#include "configure.h"
#include "peripherals.h"
#include "threads.h"

void main(void) {
    peripherals_init();

    threads_init();
    threads_loop();

    // ===== Should Not Run to HERE =====
    mcu_reset();
}