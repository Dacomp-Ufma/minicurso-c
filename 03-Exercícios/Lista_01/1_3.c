#include <stdio.h>
#include <math.h>

int main()
{
    float a = 0.0;
    double b = 0.0;

    a = sqrt(27.0);
    b = sqrt(27.0);

    if (a == b)
    {
        printf("Sao iguais");
    }
    else
    {
        printf("Sao diferentes");
    }

    return 0;
}

// resposta certa : sao diferentes, um do tipo float e outro do tipo double.
