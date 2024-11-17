#include "../include/debug.hpp"

extern "C"
{
    extern bool logInitNoCash()
    {
        for(unsigned int i = 0; i < 6; i++)
        {
            if("no$gba"[i] != NOCASH_SIG[i]) return false;
        }

        return true;
    }

        extern void logOutputNoCash(unsigned char level, const char* message)
        {
            (void)level;
            while(*message)
            {
                REG_NOCASH_LOG = *message++;
            }

            REG_NOCASH_LOG = '\n';
        }

}