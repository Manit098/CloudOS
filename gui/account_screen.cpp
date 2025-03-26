#include "graphics.h"

void account_screen() {
    draw_rectangle(0, 0, 1024, 576, 0x000000);  // Black background
    draw_text(350, 100, "Create Account", 0xFFFFFF);
    
    draw_text(200, 200, "Username:", 0xFFFFFF);
    draw_input_box(350, 200);

    draw_text(200, 250, "Password:", 0xFFFFFF);
    draw_input_box(350, 250);

    draw_text(200, 300, "Confirm Password:", 0xFFFFFF);
    draw_input_box(350, 300);
}
