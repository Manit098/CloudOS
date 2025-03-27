all: boot.bin kernel.bin os.iso

boot.bin: bootloader/boot.asm
    nasm -f bin bootloader/boot.asm -o bootloader/boot.bin

kernel.bin: kernel/kernel.cpp
    i686-elf-g++ -ffreestanding -c kernel/kernel.cpp -o kernel/kernel.o
    i686-elf-ld -T kernel/kernel.ld -o kernel/kernel.bin kernel/kernel.o

os.iso: boot.bin kernel.bin
    mkdir -p iso/boot
    cp bootloader/boot.bin iso/boot/
    cp kernel/kernel.bin iso/boot/
    grub-mkrescue -o os.iso iso/

clean:
    rm -rf boot.bin kernel.bin os.iso iso
