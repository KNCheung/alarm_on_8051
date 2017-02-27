#include "drivers/configure.h"
#include "drivers/peripherals.h"
#include "threads.h"

void main(void) {
    peripherals_init();

    threads_init();
    threads_loop();

    // ===== Should Not Run to HERE =====
    mcu_reset();
}