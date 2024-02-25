#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

//Número de Ações +1, pois o Vetor da Carteira deverá conter o Lucro na posição 0
#define N_ACOES 8           

//Função para imprimir nossas ações da carteira
void print_investimentos(int carteira[]){
    printf("# RANDOMICA #");
    printf("\nLucro: %d", carteira[0]);
    printf("\nAs acoes escolhidas foram: ");

    for(int i=1; i<N_ACOES; i++){
        if( carteira[i] != -1){
            printf("%d ",carteira[i]);
        }
    }
}

// Função para preencher os vetores com valores de -1, seria como "Zerá-los" para nosso caso em que trabalho com apenas valores positivos
void preenche_vetor(int vetor[], int legth){
    for(int i=0; i<legth; i++){
        vetor[i] = -1;
    }
}

// Função que deverá escolher as ações de acordo com a Heurística escolhida
int escolhe_acoes_randomica(int caixa, int lucros[], int custos[], int carteira[]){
    // Primerio índice da cartera zerado, pois conterá o lucro
    carteira[0] = 0;
    // Índice para iterar sobre o vetor "carteira", começando de 1, pois a posção 0 é o lucro
    int indx_carteira = 1;

    //Vetor que conterá os índices sorteados
    int idx_sorteados[N_ACOES-1];
    // Índice para iterar sobre o vetor "idx_sorteados"
    int idx_iterator = 0;

    // Variável responsável por conter a condição do vetor de índices sorteados, nesse caso não está cehio
    int cheio = FALSE;
    // Índice da ação a ser sorteado
    int indice_randomico;

    preenche_vetor(idx_sorteados, N_ACOES-1);

    // Comando de Repetição para sortear todos os índices
    while( cheio == FALSE ){
        // Supomos que o vetor esteja cheio, para verficarmos se está realmente cheio 
        cheio = TRUE;
        for(int i=0; i<N_ACOES; i++){
            // Se encontrarmos pelo menos um -1, então o vetor não está cheio, por isso a variável volta a ser FALSE
            if(idx_sorteados[i] == -1){
                cheio = FALSE;
            }
        }
        
        //Sorteia o índice. rand() gera um número aleatório entre 0 e constante RAND_MAX. Aplicamos o operador % sobre a quantidade de ações
        indice_randomico = rand() % N_ACOES-1;

        // Variável de controle para verificarmos se sorteamos um índice já sorteado
        int igual = FALSE; 

        for(int i=0; i<N_ACOES-1; i++){
            //Se encontrarmos o índice sorteado dentro do vetor, então ele estará repetido, logo, igual deve receber TRUE
            if(indice_randomico == idx_sorteados[i]){
                igual = TRUE;
            }
        }

        //Se o índice sorteado for um novo índice (Sem estar repetido) então podemos partir para a lógica de adicioná-lo
        if (igual == FALSE){
            //Adicionamos o índice sorteado, já que um novo  
            idx_sorteados[idx_iterator] = indice_randomico;
            //Iteramos sobre o nosso idx_iterator para guardar o novo próximo sorteado na próxima "casa" do vetor
            idx_iterator ++;
            // Se couber na carteira de investimentos, adicionar melhor candidato
            if ( caixa - custos[indice_randomico] >= 0){
                //Adicionamos o valor do respectivo ao lucro total
                carteira[0] += lucros[indice_randomico];
                //Guardamos o índice da ação que compramos
                carteira[indx_carteira] = indice_randomico;
                //Reduzimos nosso caixa do respectivo custo da ação
                caixa -= custos[indice_randomico];
                //Iteramos sobre o indx_carteira
                indx_carteira++;
            }

        }
    
    }


    //Retornamos a quantidade restante de caixa, uma vez que seus valores são modificados
    return caixa;

}

//Função main :)
int main(int argc, char const *argv[]){
    //Quanto de dinheito temos em caixa
    int caixa = 100;
    
    //Vetor carteira a ser preenchido com o índice da ação comprada
    int carteira[N_ACOES] = {};

    //Nossa semente para a função rand
    srand( ( unsigned int ) time( NULL ) );

    preenche_vetor(carteira, N_ACOES);

    //Nossos vetores de lucro e custo
    int lucro[N_ACOES-1]  = {70, 20, 29, 37, 7, 5, 10};
    int custo[N_ACOES-1]  = {31, 21, 20, 19, 4, 3, 6 };
    
    //Chamamos a função atualizando o valor de caixa
    caixa = escolhe_acoes_randomica(caixa, lucro, custo, carteira);
    print_investimentos(carteira);
    printf( "\nValor em caixa: %d\n", caixa );

    return 0;
}
