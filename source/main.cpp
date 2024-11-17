#include "../include/gba.hpp"
#include "../include/draw.hpp"
#include "../include/debug.hpp"

int posX = 0;
int posY = 0;

#define REG_TM2D    *(volatile unsigned short*)(DISP_CNT+0x0108)
#define REG_TM2CNT  *(volatile unsigned short*)(DISP_CNT+0x010A)  

#define REG_TM3D    *(volatile unsigned short*)(DISP_CNT+0x010C)
#define REG_TM3CNT  *(volatile unsigned short*)(DISP_CNT+0x010E)

#define TM_FREQ1024 0x0003
#define TM_CASCADE  0x0004
#define TM_ENABLE   0x0080

int main() {
    start_display_controller();

    unsigned char black = add_color(BLACK);
    unsigned char red = add_color(RED);
    
    clear_screen(vid_mem_front, black);
    clear_screen(vid_mem_back, black);

    volatile unsigned short* buffer = vid_mem_back;

    REG_TM2D = -0x4000;
    REG_TM2CNT = TM_FREQ1024 | TM_ENABLE;

    REG_TM3CNT = TM_ENABLE;

    unsigned int sec = -1;

    char debugText[200];

    while (1) {
        clear_screen(buffer, black);

        if(REG_TM3D != sec)
        {
            sprintf(debugText, "sec: %d", sec);
            sec = REG_TM3D;
            posX++;
            logOutputNoCash(0, debugText);
        }
        
        put_pixel(buffer, posY, posX, red);

        wait_vblank();
        buffer = flip_buffers(buffer);
    }
}
