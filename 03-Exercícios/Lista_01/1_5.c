#include <stdio.h>

int main()
{
    if (printf("0"))
        printf("dentro do bloco if");
    else
        printf("dentro do bloco else");

    return 0;
}

// resposta letra d) = 0dentro do bloco if