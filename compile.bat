@echo off
cd src
:: Compile first stage of boot loader
nasm boot/boot.asm -f bin -o ../build/boot.bin

:: Compile empty_end.asm
nasm kernel/empty_end.asm -f bin -o ../build/empty_end.bin

:: Compile second stage of boot loader
nasm boot/kernel_entry.asm -f elf32 -o ../build/kernel_entry.o
wsl $WSLENV/x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m32 -c kernel/kernel.cpp -o ../build/kernel.o
cd ../build
::wsl $WSLENV/x86_64-elf-ld -o loader.bin -m elf_i386 -Ttext 0x8000 kernel_entry.o kernel.o --oformat binary
wsl $WSLENV/x86_64-elf-ld -m elf_i386 -T "../link.ld"

:: Make terminal image
wsl cat boot.bin loader.bin > bootloader.bin
wsl cat bootloader.bin empty_end.bin > os.bin

cd ..

:: Run bochs
start bochsrc.bxrc