#include "../include/gba.hpp"
#include "../include/draw.hpp"

int posX = 0;
int posY = 0;

int main() {
    start_display_controller();

    unsigned char black = add_color(BLACK);
    unsigned char red = add_color(RED);

    volatile unsigned short* buffer = vid_mem_back;

    while (1) {
        clear_screen(buffer, black);

        posX++;
        put_pixel(buffer, posY, posX, red);

        buffer = flip_buffers(buffer);
    }
}
