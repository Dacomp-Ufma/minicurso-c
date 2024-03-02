
#ifndef __NES_H_
#define __NES_H_
#include "console.h"
console* init_nes();
void nes_ppu();
void nes_cpu();
CONSOLE print();

#endif