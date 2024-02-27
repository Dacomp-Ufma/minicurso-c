#include <stdio.h>

/*
Escreva um programa em C para verificar se um caractere é uma letra, dígito ou caractere
especial.
*/

int main() {
    char caractere;

    // Entrada do usuário
    printf("Digite um caractere: ");
    scanf("%c", &caractere);

    // Verifica se é uma letra
    if ((caractere >= 'a' && caractere <= 'z') || (caractere >= 'A' && caractere <= 'Z')) {
        printf("%c é uma letra.\n", caractere);
    }
    // Verifica se é um dígito
    else if (caractere >= '0' && caractere <= '9') {
        printf("%c é um dígito.\n", caractere);
    }
    // Caso contrário, é um caractere especial
    else {
        printf("%c é um caractere especial.\n", caractere);
    }

    return 0;
}
