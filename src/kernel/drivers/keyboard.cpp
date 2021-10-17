#include "../cpu/irq.h"
#include "../utils/typedefs.h"
#include "port_io.h"
#include "vga.h"
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

extern int mode;
char userinput[255];

bool shift_pressed = false;
bool caps_lock = false;

void keyboard_handler(struct regs *r){
    unsigned char scancode;

    scancode = inb(0x60);

    if (scancode & 0x80){
        switch (scancode){
            case 0xaa: shift_pressed = false; break;
        }
    } else {
        switch(scancode) {
            case 0x0E:
                if(mode == 0){
                    backspace(1);
                    userinput[strlen(userinput)-1] = '\0';
                    break;
                }
            case 0x1c:
                if(mode == 0){
                    check_command(userinput);
                    for(int i = 0; i < 255; i++){
                        if(userinput[i] != '\0'){
                            userinput[i] = '\0';
                        }
                    }
                    set_grh();
                    break;
                }
            case 0x2a: shift_pressed = true; break;
            case 0x3a: caps_lock = !caps_lock; break;
            default:
                if(mode == 0){
                    for(int i = 0; i < 255; i++){
                        if(userinput[i] == '\0'){
                            if(caps_lock | shift_pressed) userinput[i] = sclt[scancode] - 32;
                            else userinput[i] = sclt[scancode];
                            printchr(userinput[i]);
                            break;
                        }
                    }
                }
        }
    }

    outb(0x20, 0x20);
    outb(0xa0, 0x20);
}

void keyboard_install(){
    irq_install_handler(1, keyboard_handler);
}