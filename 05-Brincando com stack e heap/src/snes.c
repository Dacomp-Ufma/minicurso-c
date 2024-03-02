#include <stdio.h>
#include <stdlib.h>
#include <snes.h>


void __snes_cpu() {
    printf("A cpu do snes rodou um clock\n");
}

void __snes_ppu() {
    printf("A ppu rodou\n");
}

CONSOLE __snes_print() {
    return SNES;
}

console* init_snes() {
    console* retorno = (console*) malloc(sizeof(console));
    retorno->cpu = __snes_cpu;
    retorno->ppu = __snes_ppu;
    retorno->print = __snes_print;
    return retorno;
}

