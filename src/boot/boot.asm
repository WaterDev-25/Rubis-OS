[org 0x7c00]
[bits 16]

KERNEL_LOCATION equ 0x1000

mov [BOOT_DISK], dl

xor ax, ax
mov es, ax
mov ds, ax
mov bp, 0x8000
mov sp, bp

mov bx, KERNEL_LOCATION
mov dh, 50

call disk_read

after_disk_read:
    mov ah, 0x0     ; clear screen and set text mode
    mov al, 0x3
    int 0x10

    call switch_pm

    jmp $

; disk includes
%include "boot/disk/disk_read.asm"

; print includes
%include "boot/print/print_string.asm"

; pm includes
%include "boot/pm/gdt.asm"
%include "boot/pm/switch_pm.asm"

BOOT_DISK: db 0
LOADING_BOOT_MSG: db "Loading boot", 10, 13, 0
EXECUTING_BOOT_MSG: db "Executing boot", 10, 13, 0
DISK_READ_ERROR_MSG: db "Disk error", 10, 13, 0

begin_pm:
    jmp KERNEL_LOCATION

times 510 - ($-$$) db 0
dw 0xAA55