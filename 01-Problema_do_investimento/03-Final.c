#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define N_ACOES 7

void zerar_carteira(int vetor[])
{
    for (int i = 0; i < N_ACOES; i++)
    {
        vetor[i] = -1;
    }
}

void imprimir_vetor(int vetor[])
{
    printf("[ ");
    for (int i = 0; i < N_ACOES; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("]");
}

int main(int argc, char const *argv[])
{
    int Caixa = 77;
    int Lucros[N_ACOES] = {70, 20, 29, 37, 7, 5, 10};
    int Custos[N_ACOES] = {31, 21, 20, 19, 4, 3, 6};

    int Razao[N_ACOES] = {};

    // Na carteira armazenaremos os indices das acoes que vamos comprar
    int carteira[N_ACOES] = {};
    zerar_carteira(carteira);
    imprimir_vetor(carteira);

    escolhe_melhores_acoes(Caixa, carteira, Razao, Custos);

    return 0;
}