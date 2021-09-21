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
    text_print.o
    vec2.o
    mem.o
    typedefs.o
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