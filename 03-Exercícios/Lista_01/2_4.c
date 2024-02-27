#include <stdio.h>

/*
Escreva um programa em C para fazer tal padrão como uma pirâmide (n linhas) com um nú-
mero que irá repetir o número na mesma linha.

ex. n = 4:
   1
  2 2
 3 3 3
4 4 4 4
*/

int main() {
    int n, i, j;

    // Entrada do usuário
    printf("Digite o número de linhas (n): ");
    scanf("%d", &n);

    // Loop para cada linha
    for (i = 1; i <= n; i++) {

        // Loop para espaços em branco
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Loop para imprimir números
        for (j = 1; j <= i; j++) {
            printf("%d ", i);
        }

        // Mova para a próxima linha
        printf("\n");
    }

    return 0;
}