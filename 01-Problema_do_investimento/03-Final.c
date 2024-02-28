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

void imprimir_carteira(int vetor[])
{
    printf("[ ");
    for (int i = 0; i < N_ACOES; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("]");
}

float escolhe_melhores_acoes(float caixa, int carteira[], float lucros[], float custos[])
{
    return 0;
}

int main(int argc, char const *argv[])
{
    float Caixa = 77;
    float Lucros[N_ACOES] = {70, 20, 29, 37, 7, 5, 10};
    float Custos[N_ACOES] = {31, 21, 20, 19, 4, 3, 6};

    float Razao[N_ACOES] = {};

    // Na carteira armazenaremos os indices das acoes que vamos comprar
    int Carteira[N_ACOES] = {};
    zerar_carteira(Carteira);
    imprimir_carteira(Carteira);

    /*
    Possiveis formas de resolver:
    [LUCRO] -> Analisar apenas pelo maior Lucro e seguir testando se é possível comprar essa ação
    [RAZAO] -> Criar um vetor Razao, armazenando a razao entre Lucro/Custo e depois comprar as ações
    pelas maiores razões disponíveis, sempre verificando logo após se é possível comprar
    [RANDOMICA] -> Escolher uma acao aleatoriamente e verificar se é possivel comprar
    */

    escolhe_melhores_acoes(Caixa, Carteira, Razao, Custos);

    return 0;
}
