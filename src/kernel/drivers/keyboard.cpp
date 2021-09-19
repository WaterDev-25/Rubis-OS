void keyboard_handler(struct regs *r){
    unsigned char scancode;

    scancode = inb(0x60);
    
    switch (scancode)
    {
        default:
            if(scancode < 0x3A)
                print("\r\nKey was pressed!");
            else
                print("\r\nKey was released!");
    }

    outb(0x20, 0x20);
    outb(0xa0, 0x20);
}

void keyboard_install(){
    irq_install_handler(1, keyboard_handler);
}