#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nes.h"
#include "snes.h"

int* bota() {
    int a = 5;
    int* b = &a;
    return b;
}

void modifica(int* var_anterior) {
    *var_anterior = 10;
}

int strlen_customizado(char* string) {
    int tamanho = 0;

    while(*string != '\0') {
        tamanho++;
        string++;
    }
    return tamanho;
}

int strlen_sem_ptrs(char string[]) {
    // Sem ponteiros baby
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i;
}

void modificaTexto(char string[]) {
    // Pegar cada caractere e diminuir 1 dele
    int tamanho = strlen_customizado(string);
    for (int i = 0; i < tamanho; i++) {
        string[i]--;
    }
}

int passagem(int por_valor, int* por_referencia);

int main(int argc, char const *argv[])
{
    int* caixa = bota();
    modifica(caixa);

    char minhaString[] = "Loren Ipsum";
    printf("Tamanho: %d\n", strlen_sem_ptrs(minhaString));
    printf("Tamanho reportado pelo original: %d\n", strlen(minhaString));

    modificaTexto(minhaString);
    printf("String final: %s\n", minhaString);


    int tamanho_a = 3;
    int* a = (int*) malloc(sizeof(int) * tamanho_a); // heap

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    int* p = &a[2];

    tamanho_a = 40000;

    a = (int*) realloc(a, sizeof(int) * tamanho_a);

    p = &a[2];

    a[3] = 4;

    free(a);


    // int strlen_customizado(char* string)

    int (*funcao)(char*) = strlen_customizado;

    printf("Funcao: %d\n", funcao("Asfalto"));

    // Inicio o console que quero jogar

    int numconsole;
    console* escolhido;
    printf("Qual o console que você quer ligar?");
    scanf("%d", &numconsole);

    switch (numconsole) {
        case SNES:
            escolhido = init_snes();
            break;
        case NES:
            escolhido = init_nes();
            break;
        default:
            printf("Console desconhecido conectado\n");
            return SNES;
    }

    escolhido->cpu();
    escolhido->ppu();
    switch (escolhido->print()) {
        case NES:
            printf("Este é um Nintendo Entertainment System\n");
            break;
        case SNES:
            printf("Este é um Super Nintendo Entertainment System\n");
            break;
    }



    printf("%d\n", *caixa);
    return 0;
}



// Cálculo maluquinho da pilha de execução
// Sem ptr
// main
// sizeof(argc) = 0;
// sizeof(argv) = 0;
// sizeof(caixa) = 8; (ptr)
// sizeof(minhaString) = 100(str)

// strlen_sem_ptrs
// sizeof(string) = 100(str)
// sizeof(tamanho) = 4(int)

// 212 bytes

// Cálculo com ptrs
// main
// sizeof(argc) = 0;
// sizeof(argv) = 0;
// sizeof(caixa) = 8; (ptr)
// sizeof(minhaString) = 100(str)

// strlen
// sizeof(string) = 8(ptr)
// sizeof(tamanho) = 4(ptr)

// 120 bytes
