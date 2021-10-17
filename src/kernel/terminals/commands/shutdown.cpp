#include "../../utils/typedefs.h"
#include "../../drivers/vga.h"
#include "../../terminals/commands/shutdown.h"
#include "../../kernel/syscall.h"

const char* ShutdownCMD::info::name = "shutdown";
const char* ShutdownCMD::info::desc = "Shutdown command";

void ShutdownCMD::exec(){
    printstr("Shutting down...\n");
    syscall::shutdown();
}