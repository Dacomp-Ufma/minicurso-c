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
int escolhe_acoes_lucro(int caixa, int lucros[], int custos[], int carteira[]){
    // Primerio índice da cartera zerado, pois conterá o lucro
    carteira[0] = 0;
   
    //Variável que vai armazenar o índice da melhor ação
    int indice_melhor_acao = 0;
    
    // Encontrar o melhor Lucro e adicioná-lo/comprá-lo se tiver caixa suficiente
    for ( int indx_carteira = 1; indx_carteira < N_ACOES; indx_carteira++){
        // Supomos sempre o primeiro lucro como melhor
        int melhor_lucro = lucros[0];

        //Verificamos se existe algum lucro maior que ele, se existir, este será o novo maior lucro e guardamos seu índice
        for ( int i = 0; i < N_ACOES-1; i++ ){
            if (lucros[i] > melhor_lucro){
                indice_melhor_acao = i;
                melhor_lucro = lucros[i];
            }
        }

        // Se couber na carteira de investimentos, adicionar melhor lucro e retirar o seu custo da carteira
        if ( caixa - custos[indice_melhor_acao] >= 0 ){
            //Adicionando o valor do respectivo lucro ao lucro total
            carteira[0] += lucros[indice_melhor_acao];
            //Guardamos o índice da ação que compramos
            carteira[indx_carteira] = indice_melhor_acao;
            //Reduzimos o nosso caixa do respectivo custo da ação
            caixa -= custos[indice_melhor_acao];
            //Aqui "apagamos" o lucro já utilizado, transformando-o em -1
            lucros[indice_melhor_acao] = -1;
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
    caixa = escolhe_acoes_lucro(caixa, lucro, custo, carteira);
    print_investimentos(carteira);
    printf( "\nValor em caixa: %d\n", caixa );

    return 0;
}
