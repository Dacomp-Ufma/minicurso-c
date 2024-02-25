#include <stdio.h>
/*
Usando vetores, codifique um programa para solicitar 5 números, via teclado, e exibi-los na
ordem inversa àquela em que foram fornecidos.
*/

int main(){
  int num[5];

  printf( "Por favor, escreva 5 número em uma mesma linha separados por espaço.\n" );
  for (int i = 0; i < 5; i++) {
    scanf("%d", &num[i]);
  }

  printf( "Os mesmos números em ordem inversa:\n" );
  for (int i = 4; i >= 0; i--) {
    printf("%d ", num[i]);
  }
}