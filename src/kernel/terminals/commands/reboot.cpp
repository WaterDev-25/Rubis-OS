#include "../../utils/typedefs.h"
#include "../../drivers/vga.h"
#include "../../terminals/commands/reboot.h"
#include "../../kernel/syscall.h"

const char* RebootCMD::info::name = "reboot";
const char* RebootCMD::info::desc = "Reboot command";

void RebootCMD::exec(){
    printstr("Reboot...\n");
    syscall::reboot();
}