global _start

[bits 32]
[extern loader_main]

_start:
    call loader_main
    jmp $