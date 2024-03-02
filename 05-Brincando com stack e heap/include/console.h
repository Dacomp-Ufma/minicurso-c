
#ifndef __CONSOLE__H_
#define __CONSOLE__H_

typedef enum {NES, SNES} CONSOLE; 

typedef struct console {
    void (*cpu)();
    void (*ppu)();
    CONSOLE (*print)();
} console;

#endif