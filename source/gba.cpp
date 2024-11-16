#include "../include/gba.hpp"

volatile unsigned short* scanline_counter = (volatile unsigned short*) 0x04000006;

void start_display_controller(){ 
    DISP_CNT = MODE4 | BG2; 
}

volatile unsigned short* flip_buffers(volatile unsigned short* buffer) {
    if(buffer == vid_mem_front) {
        DISP_CNT &= ~SHOW_BACK;
        return vid_mem_back;
    } else {
        DISP_CNT |= SHOW_BACK;
        return vid_mem_front;
    }
}

void wait_vblank()
{
    while(*scanline_counter < 160);
}
