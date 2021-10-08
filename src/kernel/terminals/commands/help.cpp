#include "../../utils/typedefs.h"
#include "../../drivers/vga.h"
#include "../../utils/string.h"
#include "../../terminals/commands/help.h"

#include "../../terminals/commands/shutdown.h"
#include "../../terminals/commands/gmod.h"
#include "../../terminals/commands/reboot.h"

const char* HelpCMD::info::name = "HELP";
const char* HelpCMD::info::desc = "Help command";

/* table comming soon */
void addHelpCMD(const char* name, const char* desc, const bool deprecated){
    printstr(name);
    printstr("     ");
    printstr(desc);
    printstr("     ");
    printstr("Deprecated: ");
    printstr(btoa(deprecated));
}

void HelpCMD::exec(){
    addHelpCMD(ShutdownCMD::info::name, ShutdownCMD::info::desc, ShutdownCMD::info::deprecated);
    printstr("\n\r");
    addHelpCMD(GmodCMD::info::name, GmodCMD::info::desc, GmodCMD::info::deprecated);
    printstr("\n\r");
    addHelpCMD(RebootCMD::info::name, RebootCMD::info::desc, RebootCMD::info::deprecated);
}