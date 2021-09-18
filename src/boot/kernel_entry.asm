global _start

[bits 32]
[extern loader_main]

;%include "kernel/cpu/idt.asm"

_start:
    call loader_main
    jmp $