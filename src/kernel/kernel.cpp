#include "drivers/text_print.cpp"
#include "cpu/idt.cpp"
#include "cpu/isr.cpp"
#include "cpu/irq.cpp"
#include "cpu/timer.cpp"
#include "drivers/keyboard.cpp"

extern "C" void loader_main(){
    idt_install();
    isrs_install();
    irq_install();
    asm volatile("sti");
    timer_install();
    keyboard_install();

    SetCursorPosition(PositionFromCoords(0, 0));
    print("WaterOS x86");

    return;
}