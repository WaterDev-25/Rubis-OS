section .text

[bits 32]
[extern loader_main]

call loader_main
jmp $

%include "kernel/cpu/interrupt.asm"

section .rodata