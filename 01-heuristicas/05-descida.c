#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define N_ACOES 8
#define TAM_V 100

typedef struct investimentos {
    int quantidade;
    int lucros[N_ACOES];
    int custos[N_ACOES];
} Investimentos;

void print_investimentos(Investimentos* investimentos) {
    int i = 0;
    int total_custo = 0, total_lucro = 0;

    printf("-\tInvestimento\tLucro\n");
    while (i < N_ACOES && investimentos->lucros[i] != 0) {
        printf("-\t%d\t\t%d\t\n", investimentos->custos[i], investimentos->lucros[i]);
        total_custo += investimentos->custos[i];
        total_lucro += investimentos->lucros[i];
        i++;
    }
    printf("Total\t%d\t\t%d\t\n", total_custo, total_lucro);
}

Investimentos constroi_solucao(int* caixa, Investimentos* acoes) {
    Investimentos carteira = {
        0,
        { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
        { 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    unsigned int rand_idx;
    int candidato[ 2 ];

    unsigned int inicio = 0, i;

    while ( inicio < N_ACOES ){

        // Sorteia o candidato atual
        rand_idx = rand(  ) % N_ACOES + inicio;
        candidato[ 0 ] = acoes->lucros[ rand_idx ];
        candidato[ 1 ] = acoes->custos[ rand_idx ];

        // Se couber na carteira de investimentos, adicionar melhor candidato
        if ( (*caixa) - candidato[ 1 ] >= 0 ){
            carteira.lucros[ carteira.quantidade ] = candidato[ 0 ];
            carteira.custos[ carteira.quantidade ] = candidato[ 1 ];
            carteira.quantidade++;
            (*caixa) -= candidato[ 1 ];
        }

        // Atualizar candidatos
        acoes->lucros[ rand_idx ] = acoes->lucros[ inicio ];
        acoes->custos[ rand_idx ] = acoes->custos[ inicio ];
        acoes->lucros[ inicio ] = candidato[ 0 ];
        acoes->custos[ inicio ] = candidato[ 1 ];
        inicio++;
    }
    
    return carteira;
}

Investimentos* vizinhos(int caixa, Investimentos resposta, Investimentos* acoes) {
    Investimentos* vizinhanca = (Investimentos*)malloc(TAM_V * sizeof(Investimentos));
    for (int i = 0; i < TAM_V; i++) {
        vizinhanca[i].quantidade = 0;
        for (int j = 0; j < N_ACOES; j++) {
            vizinhanca[i].lucros[j] = resposta.lucros[j];
            vizinhanca[i].custos[j] = resposta.custos[j];
        }
    }

    int vizinho_atual = 0;
    int rand1, rand2;

    int lucro_solucao_atual = 0, lucro_vizinho_atual = 0;

    int k = 0;

    while (k < N_ACOES && resposta.lucros[k] != 0) {
        lucro_solucao_atual += resposta.lucros[k];
        k++;
    }

    for (int i = 0; i < TAM_V; i++) { // Quantidade de tentativas
        for (int j = 0; j < N_ACOES; j++) {
            vizinhanca[vizinho_atual].lucros[j] = resposta.lucros[j];
            vizinhanca[vizinho_atual].custos[j] = resposta.custos[j];
        }
        vizinhanca[vizinho_atual].quantidade = resposta.quantidade;

        for (int j = 0; j < N_ACOES / 2; j++) {
            rand1 = rand() % vizinhanca[vizinho_atual].quantidade;
            rand2 = rand() % N_ACOES + vizinhanca[vizinho_atual].quantidade;
            if (caixa + vizinhanca[vizinho_atual].custos[rand1] - acoes->custos[rand2] >= 0) {
                if (vizinhanca[vizinho_atual].custos[rand1] == 0)
                    vizinhanca[vizinho_atual].quantidade++;
                vizinhanca[vizinho_atual].lucros[rand1] = acoes->lucros[rand2];
                vizinhanca[vizinho_atual].custos[rand1] = acoes->custos[rand2];
                caixa += vizinhanca[vizinho_atual].custos[rand1] - acoes->custos[rand2];
            }
        }

        lucro_vizinho_atual = 0;
        k = 0;
        while (k < N_ACOES && vizinhanca[vizinho_atual].lucros[k] != 0) {
            lucro_vizinho_atual += vizinhanca[vizinho_atual].lucros[k];
            k++;
        }

        if (lucro_vizinho_atual > lucro_solucao_atual) {
            vizinho_atual++;
        }
    }

    if (vizinho_atual == 0)
        vizinhanca[vizinho_atual].quantidade = 0;

    return vizinhanca;
}

Investimentos descida(int caixa, Investimentos resposta, Investimentos* acoes) {

    Investimentos* vizinhanca = vizinhos(caixa, resposta, acoes);

    int rand_stop = 0;

    int lucro_solucao_atual = 0, custo_solucao_atual = 0, lucro_vizinho_atual;

    int i = 0, k = 0;

    while (k < N_ACOES && resposta.lucros[k] != 0) {
        lucro_solucao_atual += resposta.lucros[k];
        custo_solucao_atual += resposta.custos[k];
        k++;
    }

    while (vizinhanca[0].quantidade != 0 && rand_stop > 0) {
        while (i < TAM_V && vizinhanca[i].quantidade != 0) {

            rand_stop = rand() % 100;

            if (rand_stop < 10)
                break;

            lucro_vizinho_atual = 0;
            k = 0;
            while (k < N_ACOES && vizinhanca[i].lucros[k] != 0) {
                lucro_vizinho_atual += vizinhanca[i].lucros[k];
                k++;
            }

            int custo_vizinho_atual = 0;
            k = 0;
            while (k < N_ACOES && vizinhanca[i].custos[k] != 0) {
                custo_vizinho_atual += vizinhanca[i].custos[k];
                k++;
            }

            // Verifica se a ação já está presente na solução
            int acao_repetida = FALSE;
            for (int j = 0; j < vizinhanca[i].quantidade; j++) {
                if (vizinhanca[i].lucros[j] == acoes->lucros[k] && vizinhanca[i].custos[j] == acoes->custos[k]) {
                    acao_repetida = TRUE;
                    break;
                }
            }

            if (!acao_repetida && lucro_vizinho_atual > lucro_solucao_atual && custo_vizinho_atual <= caixa) {
                resposta = vizinhanca[i];
                lucro_solucao_atual = lucro_vizinho_atual;
                custo_solucao_atual = custo_vizinho_atual;
            }

            i++;
        }

        free(vizinhanca);
        vizinhanca = vizinhos(caixa, resposta, acoes);
        rand_stop = rand() % 100;
    }

    return resposta;
}

int main() {
    srand((unsigned int)time(NULL));

    int caixa = 100;
    Investimentos acoes = {
        N_ACOES,
        {41, 33, 14, 25, 32, 32, 9, 19},
        {47, 40, 17, 27, 34, 23, 5, 44}
    };

    Investimentos resposta = constroi_solucao(&caixa, &acoes);
    print_investimentos(&resposta);
    printf("Valor em caixa: %d\n", caixa);

    resposta = descida(caixa, resposta, &acoes);
    print_investimentos(&resposta);
    printf("Valor em caixa: %d\n", caixa);

    return 0;
}