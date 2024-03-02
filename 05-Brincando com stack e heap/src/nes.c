#include <stdio.h>
#include <stdlib.h>
#include <console.h>


void __nes_cpu() {
    printf("A cpu do nes rodou um clock\n");
}

void __nes_ppu() {
    printf("A ppu rodou\n");
}

CONSOLE __nes_print() {
    return NES;
}

console* init_nes() {
    console* retorno = (console*) malloc(sizeof(console));
    retorno->cpu = __nes_cpu;
    retorno->ppu = __nes_ppu;
    retorno->print = __nes_print;
    return retorno;
}

