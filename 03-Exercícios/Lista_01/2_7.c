#include <stdio.h>

/*
Escreva um programa em C para receber um valor n de entrada e “desenhar” na tela um triân-
gulo retângulo com n linhas, usando números. Cada linha será formada pelo respectivo número
da linha.

Exemplo de triângulo com n = 4
1
22
333
4444
*/

int main() {
    int n, i, j;

    // Entrada do usuário
    printf("Digite o número de linhas (n): ");
    scanf("%d", &n);

    // Loop para cada linha
    for (i = 1; i <= n; i++) {

        // Loop para imprimir números
        for (j = 1; j <= i; j++) {
            printf("%d", i);
        }

        // Mova para a próxima linha
        printf("\n");
    }

    return 0;
}