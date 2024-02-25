#include <stdio.h>

/*
Escreva um programa em C para encontrar o maior de três números dados por entrada.
*/

int main()
{
    int num1, num2, num3, maior;

    printf("Digite 3 numeros separados: "); // exemplo: 10 14 12
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 >= num2 && num1 >= num3)
    {
        maior = num1;
    }
    else if (num2 >= num1 && num2 >= num3)
    {
        maior = num2;
    }
    else
    {
        maior = num3;
    }

    printf("Maior: %d\n", maior);

    return 0;
}
