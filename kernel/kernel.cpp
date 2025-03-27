extern "C" void kernel_main() {
    unsigned short* vga = (unsigned short*)0xB8000;
    const char* msg = "Welcome to QTMOS!";
    
    for (int i = 0; msg[i] != '\0'; i++) {
        vga[i] = (0x0F << 8) | msg[i]; // White text on black
    }

    while (1); // Halt
}
