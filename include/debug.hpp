#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <iostream>

extern "C"
{
    #define NOCASH_SIG          ((char*)0x0FFFA00)
    #define REG_NOCASH_LOG      VOLADDR(0x04FFFA1C, unsigned char)
    #define VOLADDR(a, t)       (*(t volatile *)(a))

    extern bool logInitNoCash();
    extern void logOutputNoCash(unsigned char level, const char* message);
}

#endif // DEBUG_HPP