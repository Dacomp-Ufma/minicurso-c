#include <stdio.h>

int main() {
    int n, i, j, num = 1;

    // Entrada do usuário
    printf("Digite o número de linhas (n): ");
    scanf("%d", &n);

    // Loop para cada linha
    for (i = 1; i <= n; i++) {

        // Loop para imprimir números
        for (j = 1; j <= i; j++) {
            printf("%d", num++);
        }

        // Mova para a próxima linha
        printf("\n");
    }

    return 0;
}
