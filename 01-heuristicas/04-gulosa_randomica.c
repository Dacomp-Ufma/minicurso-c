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

Investimentos constroi_melhor( int* caixa, Investimentos acoes ){

    Investimentos carteira = {
        0,
        { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
        { 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    unsigned int rand_qtd, melhor_idx, contador_comparacoes;
    int melhor[ 2 ];

    unsigned int inicio = 0, i;

    while ( inicio < N_ACOES ){

        // Sorteia os candidatos atuais
        rand_qtd = rand(  ) % ( N_ACOES - ( N_ACOES / 4 ) ) + ( N_ACOES / 4 );

        // Achar o melhor candidato pelo maior valor
        melhor[ 0 ] = INT32_MIN; // Lucro
        melhor[ 1 ] = INT32_MAX; // Custo
        i = inicio;
        contador_comparacoes = 0;
        while ( i < N_ACOES && contador_comparacoes < rand_qtd ){
            if ( acoes.lucros[ i ] / acoes.custos[ i ] > melhor[ 0 ] / melhor[ 1 ] ){
                melhor[ 0 ] = acoes.lucros[ i ];
                melhor[ 1 ] = acoes.custos[ i ];
                melhor_idx = i;
            }
            i++;
            contador_comparacoes++;
        }

        // Se couber na carteira de investimentos, adicionar melhor candidato
        if ( (*caixa) - melhor[ 1 ] >= 0 ){
            carteira.lucros[ carteira.quantidade ] = melhor[ 0 ];
            carteira.custos[ carteira.quantidade ] = melhor[ 1 ];
            carteira.quantidade++;
            (*caixa) -= melhor[ 1 ];
        }

        // Atualizar candidatos
        acoes.lucros[ melhor_idx ] = acoes.lucros[ inicio ];
        acoes.custos[ melhor_idx ] = acoes.custos[ inicio ];
        acoes.lucros[ inicio ] = melhor[ 0 ];
        acoes.custos[ inicio ] = melhor[ 1 ];
        inicio++;
    }
    
    return carteira;
}

int main(){
    srand( ( unsigned int ) time( NULL ) );

    int caixa = 100;
    Investimentos acoes = {
        N_ACOES,
        { 41, 33, 14, 25, 32, 32, 9, 19 },
        { 47, 40, 17, 27, 34, 23, 5, 44 }
    };

    Investimentos resposta = constroi_melhor( &caixa, acoes );
    print_investimentos( &resposta );
    printf( "Valor em caixa: %d\n", caixa );

    return 0;
}