#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define N_ACOES 100

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
    printf("]\n");
}

void imprimir_acoes_escolhidas(int vetor[])
{
    printf("As acoes compradas foram: ");
    for (int i = 0; i < N_ACOES; i++)
    {
        if (vetor[i] != -1)
        {
            printf("%d ", vetor[i]);
        }
    }
    printf("\n");
}

float escolhe_melhores_acoes_lucro(float caixa, int carteira[], float lucros[], float custos[])
{
    float lucro = 0;

    for (int j = 0; j < N_ACOES; j++)
    {

        float maior_lucro = lucros[0];
        int indice_maior_lucro = 0;

        for (int i = 0; i < N_ACOES; i++)
        {
            if (lucros[i] > maior_lucro)
            {
                maior_lucro = lucros[i];
                indice_maior_lucro = i;
            }
        }

        if (caixa - custos[indice_maior_lucro] >= 0)
        {
            caixa -= custos[indice_maior_lucro]; // caixa = caixa - custos[indice_maior_lucro]
            carteira[indice_maior_lucro] = indice_maior_lucro;
            lucro += lucros[indice_maior_lucro];
            lucros[indice_maior_lucro] = -1;
        }
    }

    printf("\nO caixa eh: %.2f\n", caixa);
    return lucro;
}

float escolhe_melhores_acoes_razao(float caixa, int carteira[], float lucros[], float custos[], float razao[])
{
    float lucro = 0;

    for (int j = 0; j < N_ACOES; j++)
    {

        float maior_lucro = razao[0];
        int indice_maior_lucro = 0;

        for (int i = 0; i < N_ACOES; i++)
        {
            if (razao[i] > maior_lucro)
            {
                maior_lucro = razao[i];
                indice_maior_lucro = i;
            }
        }

        if (caixa - custos[indice_maior_lucro] >= 0)
        {
            caixa -= custos[indice_maior_lucro]; // caixa = caixa - custos[indice_maior_lucro]
            carteira[indice_maior_lucro] = indice_maior_lucro;
            lucro += lucros[indice_maior_lucro];
            razao[indice_maior_lucro] = -1;
        }
    }

    printf("\nO caixa eh: %.2f\n", caixa);
    return lucro;
}

void calula_razao_lucro_custo(float razao[], float lucros[], float custos[])
{

    for (int i = 0; i < N_ACOES; i++)
    {
        razao[i] = lucros[i] / custos[i];
    }
}


void imprime_vetor_float(float vetor[])
{
    printf("[ ");
    for (int i = 0; i < N_ACOES; i++)
    {
        printf("%f ", vetor[i]);
    }
    printf("]\n");
}




int main(int argc, char const *argv[])
{
    float meu_dinheiro =  469;
    float Lucros[N_ACOES] =  {49, 99, 52, 74, 60, 60, 60, 43, 89, 67, 19, 49, 28, 60, 18, 94, 22, 18, 49, 100, 82, 6, 39, 2, 85, 85, 40, 4, 58, 63, 42, 67, 36, 42, 18, 20, 96, 79, 26, 69, 24, 49, 72, 46, 68, 53, 23, 93, 44, 87, 13, 36, 10, 23, 57, 53, 27, 4, 59, 55, 66, 91, 66, 62, 34, 12, 67, 74, 56, 73, 26, 59, 83, 1, 78, 12, 69, 54, 63, 32, 34, 9, 11, 60, 66, 22, 97, 90, 9, 32, 49, 30, 12, 37, 44, 77, 35, 73, 65, 96};
    float Custos[N_ACOES] =  {54, 84, 95, 83, 14, 98, 69, 43, 52, 94, 55, 75, 21, 73, 96, 99, 1, 87, 9, 81, 78, 37, 9, 65, 96, 50, 36, 2, 31, 7, 96, 82, 90, 43, 16, 24, 81, 75, 5, 12, 38, 74, 76, 98, 30, 92, 92, 99, 66, 47, 13, 91, 66, 40, 9, 17, 72, 42, 75, 98, 60, 64, 31, 31, 39, 68, 19, 74, 61, 38, 70, 52, 100, 79, 80, 43, 1, 91, 92, 8, 99, 64, 93, 50, 70, 87, 90, 26, 29, 43, 36, 83, 17, 17, 78, 33, 34, 54, 56, 46};

    float Razao[N_ACOES] = {};

    // Na carteira armazenaremos os indices das acoes que vamos comprar
    int Carteira[N_ACOES] = {};
    zerar_carteira(Carteira);

    /*
    Possiveis formas de resolver:
    [LUCRO] -> Analisar apenas pelo maior Lucro e seguir testando se é possível comprar essa ação
    [RAZAO] -> Criar um vetor Razao, armazenando a razao entre Lucro/Custo e depois comprar as ações
    pelas maiores razões disponíveis, sempre verificando logo após se é possível comprar
    [RANDOMICA] -> Escolher uma acao aleatoriamente e verificar se é possivel comprar
    */
    calula_razao_lucro_custo(Razao, Lucros, Custos);

    float lucro = escolhe_melhores_acoes_lucro(meu_dinheiro, Carteira, Lucros, Custos);
    //20 ITENS                                100 ITENS
    //RAZAO DEU 576                           RAZAO 1324
    //LUCRO 427                               LUCRO 488

    printf("O lucro eh: %.2f\n", lucro);
    imprimir_acoes_escolhidas(Carteira);
    

    return 0;
}
