#include "../utils/typedefs.h"
#include "../drivers/text_print.h"
#include "../utils/string.h"
#include "../drivers/port_io.h"

#include "../terminals/commands/shutdown.h"
#include "../terminals/commands/gmod.h"

void set_grh(){
    printstr("\n\r>:", BACKGROUND_BLACK | FOREGROUND_LIGHTRED);
}

char testCmd[] = "test";
char helpCmd[] = "help";
char shutdownCmd[] = "shutdown";
char gmodCmd[] = "gmod";

//expiremental code
void check_command(char userinput[128]){
    if(strcmp(userinput, testCmd) == 0) {
        printstr("\n\r");
        printstr(userinput);
        printstr("\n\r");
        return;
    } else if(strcmp(userinput, shutdownCmd) == 0){
        printstr("\n\r");
        ShutdownCMD::exec();
        printstr("\n\r");
    } else if(strcmp(userinput, gmodCmd) == 0){
        printstr("\n\r");
        GmodCMD::exec();
        printstr("\n\r");
    } else if(strcmp(userinput, helpCmd) == 0){
        printstr("\n\r");
        printstr("help command");
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

void load_shell(){
    set_grh();
}