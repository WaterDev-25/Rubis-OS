#include "utils/typedefs.h"
#include "drivers/text_print.h"
#include "cpu/idt.h"
#include "cpu/isr.h"
#include "cpu/irq.h"
#include "cpu/timer.h"
#include "drivers/keyboard.h"
#include "terminals/shell.h"
#include "drivers/port_io.h"
#include "maths/maths.h"
#include "utils/string.h"

extern "C" void loader_main(){
    idt_install();
    isrs_install();
    irq_install();

    asm volatile("sti");
    
    timer_install();
    keyboard_install();

    SetCursorPosition(PositionFromCoords(0, 0));
    printstr("RubisOS has booted.\n\r", BACKGROUND_BLACK | FOREGROUND_LIGHTGRAY);
    
    load_shell();
    return;
}