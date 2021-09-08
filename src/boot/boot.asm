[org 0x7c00]
[bits 16]

KERNEL_LOCATION equ 0x1000

mov [BOOT_DISK], dl

mov bp, 0x9000
mov sp, bp

call load_boot
call execute_boot

load_boot:
    pusha
    
    mov bx, LOADING_BOOT_MSG
    call print_string
    mov bx, KERNEL_LOCATION
    mov dh, 15
    mov dl, [BOOT_DISK]
    call disk_read

    popa
    ret

execute_boot:
    mov bx, EXECUTING_BOOT_MSG
    call print_string
    call KERNEL_LOCATION
    jmp $

%include "boot/disk/disk_read.asm"
%include "boot/print/print_string.asm"

BOOT_DISK: db 0
LOADING_BOOT_MSG: db "Loading boot", 10, 13, 0
EXECUTING_BOOT_MSG: db "Executing boot", 10, 13, 0
DISK_READ_ERROR_MSG: db "Disk error", 10, 13, 0

times 510 - ($-$$) db 0
dw 0xAA55