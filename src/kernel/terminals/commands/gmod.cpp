#include "../../utils/typedefs.h"
#include "../../drivers/text_print.h"
#include "../../terminals/commands/gmod.h"

const char* GmodCMD::info::desc = "Graphic mode command";

void GmodCMD::exec(){
    printstr("gmod cmd");
    // clear screen
    // draw
}