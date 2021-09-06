@echo off
cd src
:: Compile first stage of boot loader
nasm boot/boot.asm -f bin -o ../build/boot.bin

:: Compile second stage of boot loader
nasm boot/kernel_entry.asm -f elf32 -o ../build/kernel_entry.o
wsl $WSLENV/x86_64-elf-gcc -O0 -g -ffreestanding -m32 -c kernel/kernel.c -o ../build/kernel.o
cd ../build
wsl $WSLENV/x86_64-elf-ld -o loader.bin -m elf_i386 -Ttext 0x1000 kernel_entry.o kernel.o --oformat binary

:: Make terminal image
wsl cat boot.bin loader.bin > bootloader.bin

cd ..

:: Run bochs
start bochsrc.bxrc