
#ifndef __SNES_H_
#define __SNES_H_
#include "console.h"
console* init_snes();
void snes_ppu();
void snes_cpu();
CONSOLE print();

#endif