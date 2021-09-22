#include "../utils/typedefs.h"
#include "../drivers/text_print.h"

void set_grh(){
    printstr("\n\rShell> ", BACKGROUND_BLACK | FOREGROUND_BROWN);
}

void check_command(char* userinput){
    printstr("\n\r");
    printstr(userinput);
}

void load_shell(){
    set_grh();
}