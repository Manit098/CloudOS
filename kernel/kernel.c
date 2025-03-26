#include <stdint.h>

#define VIDEO_MEMORY 0xB8000
#define WIDTH 80
#define HEIGHT 25

void clear_screen() {
    volatile char *video = (volatile char*) VIDEO_MEMORY;
    for (int i = 0; i < WIDTH * HEIGHT * 2; i++) {
        video[i] = ' ';
    }
}

void print_text(const char *str, int x, int y) {
    volatile char *video = (volatile char*) VIDEO_MEMORY + (y * WIDTH + x) * 2;
    while (*str) {
        *video++ = *str++;
        video++;  // Skip attribute byte
    }
}

void kernel_main() {
    clear_screen();
    print_text("CloudOS Booting...", 10, 10);

    boot_screen();
    account_screen();
}
