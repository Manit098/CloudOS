#include "graphics.h"

void boot_screen() {
    draw_rectangle(0, 0, 1024, 576, 0x000000);  // Black background
    draw_text(400, 250, "CloudOS", 0xFFFFFF);   // White text
}
