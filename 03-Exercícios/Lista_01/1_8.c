#include <stdio.h>

/*
Escreva um programa em C para ler a temperatura em graus centígrados e exibir uma
mensagem adequada de acordo com o estado da temperatura abaixo:

Temp < 0 então Tempo congelante
Temp 0-10, então, tempo muito frio
Temp 10-20, então, tempo frio
Temp 20-30, então, Normal
Temp 30-40, então, está quente
Temp >= 40, então, está muito quente
*/

int main()
{
    float temp;
    printf("Digite a temperatura em graus centígrados: ");
    scanf("%f", &temp);
    if (temp < 0)
        printf("Tempo congelante\n");
    else if (temp >= 0 && temp < 10)
        printf("Tempo muito frio\n");
    else if (temp >= 10 && temp < 20)
        printf("Tempo frio\n");
    else if (temp >= 20 && temp < 30)
        printf("Normal\n");
    else if (temp >= 30 && temp < 40)
        printf("Está quente\n");
    else
        printf("Está muito quente\n");
    return 0;
}
