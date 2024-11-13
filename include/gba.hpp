#ifndef GBA_HPP
#define GBA_HPP

#define WIDTH 240
#define HEIGHT 160

#define DISP_CNT            *(volatile unsigned int*)(0x04000000)
#define VRAM_MEM            0x06000000
#define VRAM_PAGE_SIZE      0x0A000
#define VRAM_MEM_BACK       (VRAM_MEM + VRAM_PAGE_SIZE)

#define MODE4 0x0004
#define BG2 0x0400

#define SHOW_BACK 0x10;

#define vid_mem			((unsigned short*)VRAM_MEM)
#define vid_mem_front	((unsigned short*)VRAM_MEM)
#define vid_mem_back	((unsigned short*)VRAM_MEM_BACK)

void start_display_controller();
volatile unsigned short* flip_buffers(volatile unsigned short* buffer);

#endif //GBA_HPP