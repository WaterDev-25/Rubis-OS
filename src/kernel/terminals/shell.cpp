#include "../utils/typedefs.h"
#include "../drivers/text_print.h"
#include "../utils/string.h"
#include "../drivers/port_io.h"

void set_grh(){
    printstr("\n\rShell> ", BACKGROUND_BLACK | FOREGROUND_LIGHTRED);
}

char testCmd[5] = "test";
char helpCmd[5] = "help";

//the code is horrible lol
void check_command(char userinput[128]){
    if(strcmp(userinput, testCmd) == 0) {
        printstr("\n\r");
        printstr(userinput);
        printstr("\n\r");
        return;
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