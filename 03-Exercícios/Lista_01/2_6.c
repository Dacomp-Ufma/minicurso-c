#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Digite o número de linhas para o triângulo: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
