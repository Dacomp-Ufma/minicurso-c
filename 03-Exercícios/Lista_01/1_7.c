#include <stdio.h>

int main()
{
    char vitamina;
    printf("Digite a letra correspondente a uma vitamina (A, B, C, D): ");
    scanf(" %c", &vitamina);

    switch (vitamina)
    {
    case 'A':
    case 'a':
        printf("Vitamina A: Essencial para a visão e o crescimento.\n");
        break;
    case 'B':
    case 'b':
        printf("Vitamina B: Importante para o metabolismo celular.\n");
        break;
    case 'C':
    case 'c':
        printf("Vitamina C: Fundamental para a reparação dos tecidos e a imunidade.\n");
        break;
    case 'D':
    case 'd':
        printf("Vitamina D: Crucial para a saúde dos ossos e absorção de cálcio.\n");
        break;
    default:
        printf("Vitamina desconhecida.\n");
    }

    return 0;
}
