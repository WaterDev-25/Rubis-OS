#include "../utils/typedefs.h"
#include "../drivers/vga.h"
#include "../utils/string.h"
#include "../drivers/port_io.h"

#include "../terminals/commands/shutdown.h"
#include "../terminals/commands/gmod.h"
#include "../terminals/commands/help.h"
#include "../terminals/commands/reboot.h"

extern int mode;

void set_grh(){
    if(mode == 0)
        printstr("\n\r>:", BACKGROUND_BLACK | FOREGROUND_LIGHTRED);
}

//char testCmd[] = "test";

//expiremental code
void check_command(char userinput[128]){
    if(mode == 0){
        if(!strcmp(userinput, "test")){ //if(strcmp(userinput, testCmd) == 0)
            printstr("\n\r");
            printstr(userinput);
            printstr("\n\r");
            return;
        } else if(!strcmp(userinput, ShutdownCMD::info::name)){
            printstr("\n\r");
            ShutdownCMD::exec();
            printstr("\n\r");
        } else if(!strcmp(userinput, RebootCMD::info::name)){
            printstr("\n\r");
            RebootCMD::exec();
            printstr("\n\r");
        } else if(!strcmp(userinput, GmodCMD::info::name)){
            printstr("\n\r");
            GmodCMD::exec();
            printstr("\n\r");
        } else if(!strcmp(userinput, HelpCMD::info::name)){
            printstr("\n\r");
            HelpCMD::exec();
            printstr("\n\r");
            return;
        } else {
            printstr("\n\r");
            printstr(userinput);
            printstr(": command not found");
            printstr("\n\r");
            return;
        }
    }
}

void load_shell(){
    set_grh();
}