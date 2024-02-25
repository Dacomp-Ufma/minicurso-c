#include <stdio.h>

/*
Qual será a saída do seguinte programa em C?

a) dentro do bloco if
b) dentro do bloco else
c) 0 dentro do bloco else
d) 0 dentro do bloco if
*/

int main()
{
    if (printf("0"))
        printf("dentro do bloco if");
    else
        printf("dentro do bloco else");

    return 0;
}

// resposta letra d) = 0 dentro do bloco if