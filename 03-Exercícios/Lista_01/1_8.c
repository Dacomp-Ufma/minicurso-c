#include <stdio.h>

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
