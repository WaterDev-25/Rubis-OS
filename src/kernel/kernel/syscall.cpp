#include "../utils/typedefs.h"
#include "../drivers/vga.h"
#include "../drivers/port_io.h"
#include "../kernel/syscall.h"

void syscall::shutdown(){
    asm volatile("outw %1, %0"
                 :
                 : "dN"((uint16_t)0xB004), "a"((uint16_t)0x2000)); //shutdown problem
}
void syscall::reboot(){
    uint8_t good = 0x02;
    while (good & 0x02)
        good = inb(0x64);
    outb(0x64, 0xFE);
    asm volatile("hlt");
}
void syscall::halt(){
    asm volatile("cli");
    asm volatile("hlt");
}