#include <stdio.h>

/*
Escreva um programa em C para converter dias específicos em anos, semanas e dias.
obs: Ignore o ano bissexto.
*/

int main()
{
    int total_dias, anos, semanas, dias;
    printf("Digite o número total de dias: ");
    scanf("%d", &total_dias);

    anos = total_dias / 365;
    semanas = (total_dias % 365) / 7;
    dias = (total_dias % 365) % 7;

    printf("%d dias equivalem a %d ano(s), %d semana(s) e %d dia(s).\n", total_dias, anos, semanas, dias);

    return 0;
}
