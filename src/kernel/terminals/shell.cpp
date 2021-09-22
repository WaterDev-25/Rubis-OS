#include "../utils/typedefs.h"
#include "../drivers/text_print.h"

void set_grh(){
    printstr("\n\rShell> ", BACKGROUND_BLACK | FOREGROUND_BROWN);
}

void load_shell(){
    set_grh();
}