#include <stdio.h>
/*
Qual será a saída do seguinte programa em C?

a) Oi esse eh o if
b) Não mostra nada
c) erro de compilação
d) Oi esse eh o else
*/

int x = 0;
int main()
{
    if (x == x)
        printf("Oi esse eh o if");
    else
        printf("Oi esse eh o else");
    return 0;
}

// resposta letra a) = Oi esse eh o if