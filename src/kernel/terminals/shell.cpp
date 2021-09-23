#include "../utils/typedefs.h"
#include "../drivers/text_print.h"

void set_grh(){
    printstr("\n\rShell> ", BACKGROUND_BLACK | FOREGROUND_BROWN);
}

char testCmd[5] = "test";
char helpCmd[5] = "help";

// VERY GLITCHED LOL
void check_command(char userinput[128]){
    if(StringStartsWith(userinput, testCmd)) {
        printstr("\n\r");
        printstr(userinput);
    } else if(StringStartsWith(userinput, helpCmd)){
        printstr("\n\r");
        printstr("It's help command x).");
    } else {
        printstr("\n\r");
        printstr(userinput);
        printstr(": command not found");
    }
}

void load_shell(){
    set_grh();
}