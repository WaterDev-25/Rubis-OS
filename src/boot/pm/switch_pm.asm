[bits 16]

switch_pm:
    cli
    lgdt [gdt_descriptor]

    mov eax, cr0
    or eax, 0x1
    mov cr0, eax

    jmp CODE_SEG:init_pm

[bits 32]

init_pm:
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

; DECOMMENT
    ;mov ebp, 0x90000
    ;mov esp, ebp
    
    ; UNCOMMENT LATER
    ;mov esi, mode_info_block
    ;mov edi, 9000h
    ;mov ecx, 64
    ;rep movsd

    call begin_pm