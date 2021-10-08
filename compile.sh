cd src
# Compile boot.asm
nasm boot/boot.asm -f bin -o ../build/boot.bin

# Compile empty_end.asm
nasm kernel/empty_end.asm -f bin -o ../build/empty_end.bin

# Compile kernel -- -Ttext 0x8000
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/kernel.cpp -o ../build/kernel.o -I kernel
nasm boot/kernel_entry.asm -f elf32 -o ../build/kernel_entry.o

# Compile cpu/
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/cpu/idt.cpp -o ../build/idt.o -I cpu
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/cpu/irq.cpp -o ../build/irq.o -I cpu
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/cpu/isr.cpp -o ../build/isr.o -I cpu
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/cpu/timer.cpp -o ../build/timer.o -I cpu

# Compile drivers/
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/drivers/keyboard.cpp -o ../build/keyboard.o -I drivers
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/drivers/port_io.cpp -o ../build/port_io.o -I drivers
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/drivers/vga.cpp -o ../build/vga.o -I drivers

# Compile maths/
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/maths/vec2.cpp -o ../build/vec2.o -I maths
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/maths/math.cpp -o ../build/math.o -I maths

# Compile memory/
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/memory/mem.cpp -o ../build/mem.o -I mem

# Compile utils/
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/utils/typedefs.cpp -o ../build/typedefs.o -I utils
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/utils/string.cpp -o ../build/string.o -I utils

# Compile kernel/
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/kernel/syscall.cpp -o ../build/syscall.o -I kernel

# Compile terminals/
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/terminals/shell.cpp -o ../build/shell.o -I terminals

# Compile terminals/commands/
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/terminals/commands/shutdown.cpp -o ../build/shutdown.o -I commands
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/terminals/commands/gmod.cpp -o ../build/gmod.o -I commands
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/terminals/commands/help.cpp -o ../build/help.o -I commands
x86_64-elf-gcc -ffreestanding -mno-red-zone -m32 -c kernel/terminals/commands/reboot.cpp -o ../build/reboot.o -I commands

cd ../build
#x86_64-elf-ld -o loader.bin -m elf_i386 -Ttext 0x8000 kernel_entry.o kernel.o --oformat binary
x86_64-elf-ld -m elf_i386 -T "../link.ld"

# Make terminal image
cat boot.bin loader.bin > bootloader.bin
cat bootloader.bin empty_end.bin > os.bin

cd ..

# Run bochs
bochs -f bochsrc.bxrc