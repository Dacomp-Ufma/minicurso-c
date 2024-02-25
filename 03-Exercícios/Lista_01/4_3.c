#include <stdio.h>

#define true 1
#define false 0

/*
Dado um array de n-1 inteiros distintos no intervalo de 1 a n, crie um programa em C que
encontre o número que falta nele.

Por exemplo, considere o array arr = {1, 2, 3, 4, 5, 7, 8, 9, 10 } cujos elementos são distintos e
estão no intervalo de 1 a 10. O número que falta é 6.
*/

// função que retorna se um elemento está no vetor
int EncontraElemento(int *Array, int elemento, int n) {
  for (int i = 0; i < n; i++) {
    if (Array[i] == elemento) {
      return true;
    }
  }
  return false;
}
// função que verifica qual numero falta
int NumeroQueFalta(int *Array, int n) {
  for (int i = 1; i < n; i++) { // de 1 até n
    // verifica se o elemento 1 não está no vetor, depois o 2 e assim
    // sucessivamente
    if (EncontraElemento(Array, i, n) == false) {
      // Se o elemento não estiver, retorna o elemento
      return i;
    }
  }

  return false;
}

int main(){
  int tamanho_array = 10;
  int array[  ] = { 1, 2, 3, 4, 5, 7, 8, 9, 10 };

  int numero_faltante = NumeroQueFalta( array, tamanho_array );

  printf("O número que falta no array é: %d\n", numero_faltante );

  return 0;
}