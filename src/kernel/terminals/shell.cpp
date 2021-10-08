#include "../utils/typedefs.h"
#include "../drivers/vga.h"
#include "../utils/string.h"
#include "../drivers/port_io.h"

#include "../terminals/commands/shutdown.h"
#include "../terminals/commands/gmod.h"
#include "../terminals/commands/help.h"

extern int mode;

void set_grh(){
    if(mode == 0)
        printstr("\n\r>:", BACKGROUND_BLACK | FOREGROUND_LIGHTRED);
}

char testCmd[] = "test";
char helpCmd[] = "help";
char shutdownCmd[] = "shutdown";
char gmodCmd[] = "gmod";

//expiremental code
void check_command(char userinput[128]){
    if(mode == 0){
        if(!strcmp(userinput, testCmd)){ //if(strcmp(userinput, testCmd) == 0)
            printstr("\n\r");
            printstr(userinput);
            printstr("\n\r");
            return;
        } else if(!strcmp(userinput, shutdownCmd)){
            printstr("\n\r");
            ShutdownCMD::exec();
            printstr("\n\r");
        } else if(!strcmp(userinput, gmodCmd)){
            printstr("\n\r");
            GmodCMD::exec();
            printstr("\n\r");
        } else if(!strcmp(userinput, helpCmd)){
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