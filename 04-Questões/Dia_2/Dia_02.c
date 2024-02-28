#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int calcula_numero_de_digitos(int n){
    int n_digitos = 1;

    while (n / 10 != 0)
    {
        n_digitos++;          // n_digitos += 1    n_digitos = n_digitos + 1
        n = n / 10; // number/=10
    }

    return n_digitos;
}


float calcula_distancia_entre_dois_pontos_no_plano(float p1x, int p1y, int p2x, int p2y){
        //CALCULA A DISTANCIA COM A EXPRESSAO E RETORNA ESSE VALOR
}



int main(int argc, char const *argv[])
{

    // for        while          do-while
    // x = 10      x++ -> x = x+1    x=11       x--  -> x = x-1

    /*
    for(int i = 0; i < 2; i++){
        printf("%d ", i);
    }
    */

    // IMPRIMIR DE 1 ATE 100

    /*
    for(int i=0; i<100; i++){
        printf("%d\n", i+1);
    }
    */

    // SOMA DOS N NATURAIS  n = 5  -> 1 + 2 + 3 + 4 + 5

    /*
    int number;
    printf("Digite a ordem do enesimo termo da sequencia dos naturais: ");
    scanf("%d", &number);

    int n_soma = 0;

    for(int i=1; i<number+1; i++){
        n_soma = n_soma + i; // n_soma += i;
    }

    printf("A soma nos %d primeiros naturais eh: %d", number, n_soma);
    */

    // N PRIMEROS PARES

    /*
    int number;
    printf("Digite a ordem do enesimo termo da sequencia dos naturais: ");
    scanf("%d", &number);

    int n_soma = 0;

    // i = i+2
    for(int i = 2; i <= 2*number; i+=2){
        n_soma = n_soma + i; // n_soma += i;
    }

    printf("A soma nos %d primeiros naturais eh: %d", number, n_soma);

    */

    // WHILE -> O numero de repeticoes é indefinido

    /*
   int number = 1;
   while(number <= 100){
        printf("%d\n", number);
        number++;
   }

   printf("Saiu do While");
    */

    // DO WHILE -> QUEREMOS EXECUTAR O CODIGO DENTRO DO DO-WHILE PELO MENOS UMA VEZ

    /*
   int number = 101;

   do{
    printf("%d\n", number);

   } while (number <= 100);

   printf("Saiu do While");
    */

    // 2.1 ORDEM INVERSA

    //SEPARAR EM UMA FUNCAO À PARTE
    int number;
    printf("Digite um numero: ");
    scanf("%d", &number);

    int number_digitos = calcula_numero_de_digitos(number);
    
    int new_number = number;
    int new_new_number = number;

    printf("O numero de digitos eh: %d\n", number_digitos);

    float inverse_number = 0;
    int resto = 0;
    int n_vezes = number_digitos;

    for (int i = 0; i < n_vezes; i++)
    {
        resto = new_number % 10;
        new_number = new_number / 10;
        inverse_number += resto * pow(10, number_digitos - 1);
        number_digitos--;
    }

    int int_inverse_number = (int)(inverse_number);

    printf(" O inverso eh: %d\n", int_inverse_number);

    // VERIFICAR SE EH PALINDROMO

    if (new_new_number == int_inverse_number)
    {
        printf("O numero eh palindromo\n");
    }
    else
    {
        printf("O numero nao eh palindromo\n");
    }


    return 0;
}
