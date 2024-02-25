#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define TRUE 1
#define FALSE 0

//Número de Ações +1, pois o Vetor da Carteira deverá conter o Lucro na posição 0
#define N_ACOES 8             

//Função para imprimir nosso vetor de carteira
void print_investimentos(int carteira[]){
    printf("# GULOSA LUCRO #");
    printf("\nAs acoes escolhidas foram: ");
    for(int i=1; i<N_ACOES; i++){
        if( carteira[i] != -1){
            printf("%d ",carteira[i]);
        }
    }

    printf("\nLucro: %d", carteira[0]);

}

// Função para preencher os vetores com valores de -1, sera "Zerá-los" para nosso caso em que trabalho com apenas valores positivos
void preenche_vetor(int vetor[], int legth){
    for(int i=0; i<legth; i++){
        vetor[i] = -1;
    }
}

// Função que deverá escolher as ações de acordo com a Heurística escolhida
int escolhe_acoes_razao(int caixa, int lucros[], int custos[], int carteira[]){
    //Primerio índice da cartera zerado, pois conterá o lucro
    carteira[0] = 0;
   
    //Vetor que vai armazenar temporariamente nossa melhor acao, com seu lucro e custo, respectivamente.
    int melhor[ 2 ] = {};
    //Variável que vai armazenar o índice da melhor ação
    int indice_melhor_acao = 0;

    //Encontrar oa melhor razão lucro/custo e adicioná-lo/comprá-lo se tiver caixa suficiente
    for(int indx_carteira = 1; indx_carteira<N_ACOES; indx_carteira++){
        //Supomos sempre que a melhor razão lucro/custo será a da primeira ação
        melhor[0] = lucros[0];
        melhor[1] = custos[0];

        //Verificamos se existe alguma razao maior que essa, se existir, esta será a nova melhor razão e guardamos seu índice
        for ( int i = 0; i < N_ACOES-1; i++ ){
            if ( lucros[ i ] / custos[ i ] > melhor[ 0 ] / melhor[ 1 ] && custos[i] != -1){
                indice_melhor_acao = i;
                melhor[0] = lucros[i];
                melhor[1] = custos[i];
            }
        }

         
        //Se couber na carteira de investimentos, adicionar melhor lucro e retirar o seu custo da carteira
        if ( caixa - custos[indice_melhor_acao] >= 0 ){
            //Adicionando o valor do respectivo lucro ao lucro total
            carteira[0] += lucros[indice_melhor_acao];
            //Guardamos o índice da ação que compramos
            carteira[indx_carteira] = indice_melhor_acao;
            //Reduzimos o nosso caixa do respectivo custo da ação
            caixa -= custos[indice_melhor_acao];
            //Aqui "apagamos" a razão já utilizada, transformando o seu custo em -1
            custos[indice_melhor_acao] = -1;
        }

    }

    //Retornamos o valor de caixa atualizado
    return caixa;
}


//Função main :)
int main(int argc, char const *argv[]){
    //Quanto de dinheito temos em caixa
    int caixa = 100;
    
    //Vetor carteira a ser preenchido com o índice da ação comprada
    int carteira[N_ACOES] = {};

    preenche_vetor(carteira, N_ACOES);

    //Nossos vetores de lucro e custo
    int lucro[N_ACOES-1]  = {70, 20, 29, 37, 7, 5, 10};
    int custo[N_ACOES-1]  = {31, 21, 20, 19, 4, 3, 6 };
    
    //Chamamos a função atualizando o valor de caixa
    caixa = escolhe_acoes_razao(caixa, lucro, custo, carteira);
    print_investimentos(carteira);
    printf( "\nValor em caixa: %d\n", caixa );

    return 0;
}