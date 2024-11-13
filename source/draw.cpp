#include "../include/gba.hpp"
#include "../include/draw.hpp"

volatile unsigned short* palette = (volatile unsigned short*) 0x5000000;
int next_palette_index = 0;

unsigned char add_color(unsigned char r, unsigned char g, unsigned char b) {
    unsigned short color = b << 10;
    color += g << 5;
    color += r;

    palette[next_palette_index] = color;

    next_palette_index++;

    return next_palette_index - 1;
}

void put_pixel(volatile unsigned short* buffer, int row, int col, unsigned char color) {
    unsigned short offset = (row * WIDTH + col) >> 1;

    unsigned short pixel = buffer[offset];

    if (col & 1) {
        buffer[offset] = (color << 8) | (pixel & 0x00ff);
    } else {
        buffer[offset] = (pixel & 0xff00) | color;
    }
}

void clear_screen(volatile unsigned short* buffer, unsigned short color) {
    unsigned short row, col;
    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH; col++) {
            put_pixel(buffer, row, col, color);
        }
    }
}