global _start

[bits 16]
[extern loader_main]

_start:
    call loader_main
    jmp $