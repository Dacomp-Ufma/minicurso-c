#include <stdio.h>

int recursive(int i)
{
    int count = 0;
    count = count + i;
    return count;
}

int main()
{
    int i, j = 0;
    for (i = 0; i <= 5; i++)
    {
        j += recursive(i);
    }
    printf("%d\n", j);
    return 0;
}

// resposta letra c) = 15
