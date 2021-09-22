@echo off
cd src
:: Compile boot.asm
nasm boot/boot.asm -f bin -o ../build/boot.bin

:: Compile empty_end.asm
nasm kernel/empty_end.asm -f bin -o ../build/empty_end.bin

:: Compile kernel -- -Ttext 0x8000
wsl $WSLENV/x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/kernel.cpp -o ../build/kernel.o -I kernel
nasm boot/kernel_entry.asm -f elf32 -o ../build/kernel_entry.o

:: Compile cpu/
wsl $WSLENV/x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/cpu/idt.cpp -o ../build/idt.o -I cpu
wsl $WSLENV/x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/cpu/irq.cpp -o ../build/irq.o -I cpu
wsl $WSLENV/x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/cpu/isr.cpp -o ../build/isr.o -I cpu
wsl $WSLENV/x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/cpu/timer.cpp -o ../build/timer.o -I cpu

:: Compile drivers/
wsl $WSLENV/x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/drivers/keyboard.cpp -o ../build/keyboard.o -I drivers
wsl $WSLENV/x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/drivers/port_io.cpp -o ../build/port_io.o -I drivers
wsl $WSLENV/x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/drivers/text_print.cpp -o ../build/text_print.o -I drivers

:: Compile maths/
wsl $WSLENV/x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/maths/vec2.cpp -o ../build/vec2.o -I maths

:: Compile memory/
wsl $WSLENV/x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/memory/mem.cpp -o ../build/mem.o -I mem

:: Compile utils/
wsl $WSLENV/x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/utils/typedefs.cpp -o ../build/typedefs.o -I utils

:: Compile terminals/
wsl $WSLENV/x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/terminals/shell.cpp -o ../build/shell.o -I terminals

cd ../build
::wsl $WSLENV/x86_64-elf-ld -o loader.bin -m elf_i386 -Ttext 0x8000 kernel_entry.o kernel.o --oformat binary
wsl $WSLENV/x86_64-elf-ld -m elf_i386 -T "../link.ld"

:: Make terminal image
wsl cat boot.bin loader.bin > bootloader.bin
wsl cat bootloader.bin empty_end.bin > os.bin

cd ..

:: Run bochs
start bochsrc.bxrc