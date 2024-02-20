#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define N_ACOES 8

typedef struct _investimentos_{
    unsigned int quantidade;
    int lucros[ N_ACOES ];
    int custos[ N_ACOES ];
} Investimentos;

void print_investimentos( Investimentos* investimentos ){
    int i = 0;
    int total_custo = 0, total_lucro = 0;

    printf( "-\tInvestimento\tLucro\n" );
    while( i < N_ACOES && investimentos->lucros[ i ] != NULL ){
        printf( "-\t%d\t\t%d\t\n", investimentos->custos[ i ], investimentos->lucros[ i ] );
        total_custo += investimentos->custos[ i ];
        total_lucro += investimentos->lucros[ i ];
        i++;
    }
    printf( "Total\t%d\t\t%d\t\n", total_custo, total_lucro );
}

Investimentos constroi_randomico( int* caixa, Investimentos acoes ){

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
        candidato[ 0 ] = acoes.lucros[ rand_idx ];
        candidato[ 1 ] = acoes.custos[ rand_idx ];

        // Se couber na carteira de investimentos, adicionar melhor candidato
        if ( (*caixa) - candidato[ 1 ] >= 0 ){
            carteira.lucros[ carteira.quantidade ] = candidato[ 0 ];
            carteira.custos[ carteira.quantidade ] = candidato[ 1 ];
            carteira.quantidade++;
            (*caixa) -= candidato[ 1 ];
        }

        // Atualizar candidatos
        acoes.lucros[ rand_idx ] = acoes.lucros[ inicio ];
        acoes.custos[ rand_idx ] = acoes.custos[ inicio ];
        acoes.lucros[ inicio ] = candidato[ 0 ];
        acoes.custos[ inicio ] = candidato[ 1 ];
        inicio++;
    }
    
    return carteira;
}

int main(){

    srand( ( unsigned int ) time( NULL ) );

    int caixa = 100;
    Investimentos acoes = {
        N_ACOES,
        { 41, 33, 14, 25, 32, 32, 9, 19 }, // Lucros
        { 47, 40, 17, 27, 34, 23, 5, 44 }  // Custos
    };

    Investimentos resposta = constroi_randomico( &caixa, acoes );
    print_investimentos( &resposta );
    printf( "Valor em caixa: %d\n", caixa );

    return 0;
}