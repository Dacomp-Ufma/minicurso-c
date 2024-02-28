#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int soma_de_duas_parcelas(int a, int b);

void imprime_menu(){
    printf("----------MENU----------");
    printf("\n[0] - Encerrar o Programa");
    printf("\n[1] - Calcular Media Aritmetica");
    printf("\n[2] - Calcular Media Quadratica\n");
}


float calcular_media_aritmetica(float vetor[], int tamanho_do_vetor){
    float soma_valores = 0;
    for(int i=0; i<tamanho_do_vetor; i++){
        soma_valores += vetor[i];
    }

    return soma_valores/tamanho_do_vetor;
}

float calcular_media_quadratica(float vetor[], int tamanho){
    float media_ari = calcular_media_aritmetica(vetor, tamanho);
    float media_qua = sqrt(media_ari);
    return media_qua;
}



int main(int argc, char const *argv[])
{
    /*
    //VETORES
        //int vetor[7] = {7,6,5,4,3,2,1};

    int vetor[] = {1,2,3,4,5,6,2024,10,10,10,-1,-4,26,2025,2025};

    //sizeof()

    int tamanho = sizeof(vetor)/sizeof(int);

    printf("O tamnho do vetor eh: %d\n", tamanho);

    vetor[tamanho-1] = 397;

    //iterar -> andar pelo vetor
    //IMPRIME NA DO MENOR INDICE PARA O MAIOR
    for(int i=0; i<tamanho; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");

    //IMPRIME DE TRAS PRA FRENTE
    for(int i=tamanho-1; i>=0; i--){
        printf("%d ", vetor[i]);
    }


    //ENCONTRA MAIOR
    int maior = vetor[0];

    for(int i=0; i<tamanho; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
        }
    }

    printf("\nO maior valor eh: %d", maior);

    //ENCONTRA MENOR

    int menor = vetor[0];

    for(int i=0; i<tamanho; i++){
        if(vetor[i]<menor){
            menor = vetor[i];
        }
    }

    printf("\nO menor valor eh: %d", menor);
    */

    // 4.3
    /*

    int vetor[] = {1,2,3,4,5,7,8,9,10};

    int tamanho = sizeof(vetor)/sizeof(int);

    int numero_que_falta;

    //COM BREAK
     for(int i=0; i<tamanho; i++){
        if(vetor[i] != i+1){
            numero_que_falta = i+1;
            break;
        }
    }

    //SEM BREAK
    //Flag -> Serve para verificar se determinacao situação foi atingida
    int achou_o_numero_diferente = 0;

    for(int i=0; i<tamanho; i++){
        if(vetor[i] != i+1 && achou_o_numero_diferente == 0){
            numero_que_falta = i+1;
            achou_o_numero_diferente = 1;
        }
    }

    printf("O numero que falta eh: %d", numero_que_falta);


    */

    /*
    //4.4
    int vetor[] = {7, 3, 6, 1, 4, 5};

    int tamanho = sizeof(vetor) / sizeof(int);

    int menor = vetor[0];
    int indice_do_menor;

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] < menor)
        {
            menor = vetor[i];
            indice_do_menor = i;
        }
    }

    int maior = vetor[indice_do_menor + 1];
    int indice_do_maior;

    for (int i = indice_do_menor + 1; i < tamanho; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
            indice_do_maior = i;
        }
    }

    printf("Vc deve comprar no dia %d e deve vender no dia %d", indice_do_menor+1, indice_do_maior+1);

    */

    /*
    char nome[200] = {};

    printf("Digite seu nome, por favor: ");
    scanf("%s", &nome);

    int tamanho = sizeof(nome)/sizeof(char);
    printf("O tamanho do vetor eh: %d\n", tamanho);

    //IMPRIME COM FOR
    for(int i=0; i<tamanho-1; i++){
        printf("%c", nome[i]);
    }

    //IMPRIME DIRETO
    printf("\nMeu nome eh: %s", nome);
    */

    // MATRIZZEEEESSS
    /*
    int matrix[3][2] = {
        {1,2}, 
        {6,5},
        {10,11}
        };

    //IMPRIME LINHA POR LINHA  i representa as linhas e j representa as colunas
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            printf("%d ", matrix[i][j]);
        }
    }

    printf("\n");

    //IMPRIME COLUNA POR COLUNA i representar as colunas e o j vai representar as linhas;

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            printf("%d ", matrix[j][i]);
            //Primeira iteracao do i  matrix[j][0]
            //Segunda iteracao do i  matrix[j][1]
        }
    }

    printf("\n");

    int matrix_quadrada[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    int soma_da_diagonal = 0;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if( i == j){
                soma_da_diagonal += matrix_quadrada[i][j];
            }
        }
    }

   for(int i=0; i<3; i++){
        soma_da_diagonal += matrix_quadrada[i][i];
   }


    printf("A soma da diagonal eh: %d", soma_da_diagonal);


    //PARA O LAR -> TENTAR FAZER A SOMA DA DIAGONAL SECUNDARIA
    // TESTAR E TENTAR CALCULAR A NUMERO DE LINHAS E NUMERO DE COLUNAS DE UMA MATRIZ COM SIZEOF
    */



   //FUNCOES
    /*
    int soma_return = soma_de_duas_parcelas(8,2);
    printf("%d", soma_return);

    return 0;
    */


   // MINI PROJETINHO -> MENU PARA CALCULAR DOIS TIPOS DE MEDIA
   //CRIAR UMA FLAG PARA SABER QUANDO A PESSOA QUER DESLIGAR O MENU
   int run = TRUE;

   //VETOR DE VALORES PARA CALCULAS AS MEDIAS
   float valores[] = {1,2,3,4,5,6,7,8,9,10};
   int tamanho = sizeof(valores)/sizeof(float);
  
   while( run == TRUE){
    //IMPRIMIR O MENU, CERTO? CERTO, CONSEGUIMOS
    imprime_menu();
    int opcao_escolhida;
    scanf("%d", &opcao_escolhida);

    switch (opcao_escolhida)
    {
        case 0: 
            {
            run = FALSE;
            } break;
        case 1: 
            {
                float media_aritmetica = calcular_media_aritmetica(valores, tamanho);
                printf("A media aritmetica eh: %f\n", media_aritmetica);
            } break;
        case 2: 
            {
                float media_quadratica = calcular_media_quadratica(valores, tamanho);
                printf("A media quadratica eh: %f\n", media_quadratica);
            } break;
        default:
        printf("Digite uma opçao valida\n");
    }
    

    //VOU DA UM SCANF E ESPERAR A PESSOA ESCOLHER A OPCAO DO MENU
    // VOU VERIFICAR QUAL OPCAO A PESSAO ESCOLHEU E VOU CHAMAR A FUNCAO RESPECTIVA
   }
    


}







int soma_de_duas_parcelas(int a, int b){
    int soma = a+b;
    return soma; 
} 
