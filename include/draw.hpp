#ifndef DRAW_HPP
#define DRAW_HPP

#define RED     0x1F, 0x00, 0x00
#define GREEN   0x00, 0x1F, 0x00
#define BLUE    0x00, 0x00, 0x1F
#define BLACK   0x00, 0x00, 0x00
#define WHITE   0x1F, 0x1F, 0x1F

unsigned char add_color(unsigned char r, unsigned char g, unsigned char b);
void put_pixel(volatile unsigned short* buffer, int row, int col, unsigned char color);
void clear_screen(volatile unsigned short* buffer, unsigned short color);

#endif // DRAW_HPP