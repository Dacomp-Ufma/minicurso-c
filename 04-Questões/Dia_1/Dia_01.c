#include <math.h>
#include <stdio.h>


int main(int argc, char const *argv[]){
  

  /*
  //TIPOS DE DADOS
  //Alt -> Move uma linha para cima ou para baixo
  //Tab -> Move todo mundo para a direita
  //Shift Tab -> Move todo mundo para a esquerda

  int idade;
  float altura;
  char letra_inical;
  double mais_precisao;

  // scanf("Mesmos modificadores", &variavel)

  printf("\nDigite a primeira letra do seu nome: ");
  scanf("%c", &letra_inical);
  printf("Dgite sua idade: ");
  scanf("%d", &idade);
  printf("\nDigite sua altura ");
  scanf("%f", &altura);

  // \n -> Pular uma linha

  printf("Isso %d é um inteiro %d\n", idade, idade);
  printf("Isso %.2f é um float %.3f\n", altura, altura);
  printf("Isso %c é um caractere %c", letra_inical, letra_inical);

  //%d  -> Inteiro
  //%c  -> caractere
  //%f  -> float    %.2f -> Ele vai colocar apenas duas casas decimais
  //%f  -> double   %.2f -> Ele vai colocar apenas duas casas decimais
  */

 
  /*
  // CONDICIONAIS
  int A = 10;
  int B = 3;
  int C = 5;

  if (A != B) {
    printf("%d eh diferente de %d", A, B);
  } else{
    printf("%d eh igual a %d", A, B);
  }

  printf("\n");

  if (A >= B) {
    printf("%d maior ou igual a %d", A, B);
  } else {
    printf("%d menor a %d", A, B);
  }
  */

  /*
  if ( A == B && B == C ) {
    printf("Entao %d eh igual a %d", A, C);
  } else if( A != C){
     printf("Entao %d eh diferente %d", A, C);
  }

  printf("\n");

  if(!(A == B)){
    printf("Entao eles sao DIFERENTES");
  }

  switch(A){
    case 1:
      {
        printf("A eh iigual a 1");
      } break;
    case 2:
      {
        printf("A eh iigual a 2");
      } break;
    case 3:
      {
        printf("A eh iigual a 3");
      } break;
    case 4:
      {
        printf("A eh iigual a 4");
      } break;
    default:
      {
        printf("Valor incorreto");
      }
    

  }

  */

  //Atividades Aula 01
 //1.2
 /*
  int number;
  printf("Digite um numero: ");
  scanf("%d", &number);
  
  // % -> O resto da da divisao de a por b  a%b

  if( number%2 == 0){
      printf("O numero %d eh PAR", number);
  } else{
      printf("O numero %d eh IMPAR", number);
  }
 */

  /*
  //1.6
  int dias_totais;
  int ano, meses, semanas;
 
  printf("Digite um numero de dias valido: ");
  scanf("%d", &dias_totais);

  ano = dias_totais/365;
  dias_totais = dias_totais%365;

  meses = dias_totais/30;
  dias_totais = dias_totais%30;

  semanas = dias_totais/7;
  dias_totais = dias_totais%7;

  printf("A quantidade de dias equivale a: %d anos, %d meses, %d semana(s), %d dias", ano, meses, semanas, dias_totais);

  */

    return 0;
}
