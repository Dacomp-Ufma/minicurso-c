#include <stdio.h>

/*
Escreva um programa em C para verificar se um determinado número de entrada
é par ou ímpar.
*/

int main()
{
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    if (numero % 2 == 0)
    {
        printf("%d é par.\n", numero);
    }
    else
    {
        printf("%d é ímpar.\n", numero);
    }
    return 0;
}
