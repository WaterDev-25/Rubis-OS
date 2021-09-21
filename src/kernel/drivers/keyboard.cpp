#include "../cpu/irq.h"
#include "../utils/typedefs.h"
#include "port_io.h"
#include "text_print.h"

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

void keyboard_handler(struct regs *r){
    unsigned char scancode;

    scancode = inb(0x60);
    
    if (scancode & 0x80){ } else {
        switch(scancode) {
            case 0x0E:
                //SetCursorPosition(get_cursor_position()); // NOT GOOD

            default:
                printchr(sclt[scancode]);
                /*if(scancode < 0x3A)
                    printstr("\r\nKey was pressed!");
                else
                    printstr("\r\nKey was released!");*/
        }
    }

    outb(0x20, 0x20);
    outb(0xa0, 0x20);
}

void keyboard_install(){
    irq_install_handler(1, keyboard_handler);
}