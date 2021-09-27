#include "../cpu/irq.h"
#include "../utils/typedefs.h"
#include "port_io.h"
#include "text_print.h"
#include "../maths/vec2.h"
#include "../terminals/shell.h"
#include "../utils/string.h"

const char sclt[] = {
    0, 0, '1', '2',
    '3', '4', '5', '6',
    '7', '8', '9', '0',
    '-', '=', 0, 0,
    'q', 'w', 'e', 'r',
    't', 'y', 'u', 'i',
    'o', 'p', '[', ']',
    0, 0, 'a', 's',
    'd', 'f', 'g', 'h',
    'j', 'k', 'l', ';',
    '\'', '`', 0, '\\',
    'z', 'x', 'c', 'v',
    'b', 'n', 'm', ',',
    '.', '/', 0, '*',
    0, ' '
};

char userinput[255];

void keyboard_handler(struct regs *r){
    unsigned char scancode;

    scancode = inb(0x60);

    if (scancode & 0x80){ } else {
        switch(scancode) {
            case 0x0E:
                backspace(1);
                userinput[strlen(userinput)-1] = '\0';
                break;
            case 0x1c:
                check_command(userinput);
                for(int i = 0; i < 255; i++){
                    if(userinput[i] != '\0'){
                        userinput[i] = '\0';
                    }
                }
                set_grh();
                break;
            default:
                for(int i = 0; i < 255; i++){
                    if(userinput[i] == '\0'){
                        userinput[i] = sclt[scancode];
                        printchr(userinput[i]);
                        break;
                    }
                }
        }
    }

    outb(0x20, 0x20);
    outb(0xa0, 0x20);
}

void keyboard_install(){
    irq_install_handler(1, keyboard_handler);

    for(int i = 0; i < 255; i++){
        userinput[i] = 0;
    }
}