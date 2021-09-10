#include "text_print.cpp"

extern "C" void loader_main(){
    SetCursorPosition(PositionFromCoords(0, 0));
    print("Hello, World!\n\rtest");
    return;
}