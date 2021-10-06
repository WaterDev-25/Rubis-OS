#include "../../utils/typedefs.h"
#include "../../drivers/vga.h"
#include "../../terminals/commands/shutdown.h"

const char* ShutdownCMD::info::name = "SHUTDOWN";
const char* ShutdownCMD::info::desc = "Shutdown command";

void ShutdownCMD::exec(){
    printstr("Shutting down...\n");
    asm volatile("outw %1, %0" : : "dN" ((uint16_t)0xB004), "a" ((uint16_t)0x2000));
}