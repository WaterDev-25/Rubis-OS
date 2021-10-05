#include "utils/typedefs.h"
#include "drivers/text_print.h"
#include "cpu/idt.h"
#include "cpu/isr.h"
#include "cpu/irq.h"
#include "cpu/timer.h"
#include "drivers/keyboard.h"
#include "terminals/shell.h"
#include "drivers/port_io.h"
#include "maths/math.h"
#include "utils/string.h"

extern "C" void loader_main(){
    idt_install();
    isrs_install();
    irq_install();

    asm volatile("sti");
    
    timer_install();
    keyboard_install();

    //colline(0, BACKGROUND_CYAN);
    //colline(24, BACKGROUND_CYAN);

    SetCursorPosition(PositionFromCoords(0, 0));
    printstr("WaterCorp Rubis-OS Version b0.1\n\r", BACKGROUND_BLACK | FOREGROUND_WHITE);
    printstr("(C)Copyright Water Corp 2021-2021\n\r", BACKGROUND_BLACK | FOREGROUND_WHITE);

    load_shell();
    return;
}