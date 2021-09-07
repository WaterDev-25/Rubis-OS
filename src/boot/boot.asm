[org 0x7c00]
[bits 16]

KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl

mov bp, 0x7c00
mov sp, bp

call load_boot
call execute_boot

load_boot:
    pusha
    mov bx, LOADING_BOOT_MSG
    call print_string
    mov bx, KERNEL_OFFSET
    mov dh, 15
    mov dl, [BOOT_DRIVE]
    call disk_read
    popa
    ret

execute_boot:
    mov bx, EXECUTING_BOOT_MSG
    call print_string
    call KERNEL_OFFSET
    jmp $


%include "boot/disk/disk_read.asm"
%include "boot/print/print_string.asm"
%include "boot/pm/gdt.asm"

BOOT_DRIVE: db 0
LOADING_BOOT_MSG: db "Loading boot", 10, 13, 0
EXECUTING_BOOT_MSG: db "Executing boot", 10, 13, 0
DISK_READ_ERROR_MSG: db "Disk error", 10, 13, 0

times 510-($-$$) db 0
dw 0xaa55