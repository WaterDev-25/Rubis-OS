#include "../../utils/typedefs.h"
#include "../../drivers/vga.h"
#include "../../terminals/commands/gmod.h"

const char* GmodCMD::info::name = "GMOD";
const char* GmodCMD::info::desc = "Graphic mode command";

extern int mode;

void GmodCMD::exec(){
    mode = 1;

    // clear screen
    // code
    clear(BACKGROUND_LIGHTGRAY); //expiremental

    // draw
    colline(0, BACKGROUND_CYAN);
    colline(24, BACKGROUND_CYAN);

    disable_cursor();
    SetCursorPosition(PositionFromCoords(0, 0));
    printstr("WaterCorp Rubis-OS Version b0.1\n\r", BACKGROUND_CYAN | FOREGROUND_WHITE);
}