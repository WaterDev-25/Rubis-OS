OUTPUT_FORMAT(binary)

ENTRY (loader_main)

INPUT
(
    kernel_entry.o
    kernel.o
    idt.o
    irq.o
    isr.o
    timer.o
    keyboard.o
    port_io.o
    vga.o
    vec2.o
    math.o
    string.o
    mem.o
    shell.o
    typedefs.o
    shutdown.o
    gmod.o
    help.o
)

OUTPUT
(
    loader.bin
)

SECTIONS
{
    . = 0x8000;

    .text : ALIGN(0x1000)
    {
        *(.text)
    }

    .idt BLOCK(0x1000) : ALIGN(0x1000)
    {
        _idt = .;
        . = . + 0x1000;
    }

    .data : ALIGN(0x1000)
    {
        *(.data)
    }

    .rodata : ALIGN(0x1000)
    {
        *(.rodata)
    }
    
    .bss : ALIGN(0x1000)
    {
        *(COMMON)
        *(.bss)
    }
}