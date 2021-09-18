#include "drivers/text_print.cpp"
#include "cpu/idt.cpp"

extern "C" void loader_main(){ 
    SetCursorPosition(PositionFromCoords(0, 0));

    return;
}