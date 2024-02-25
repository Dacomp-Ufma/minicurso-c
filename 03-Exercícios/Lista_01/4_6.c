#include <stdio.h>

/*
Escreva um programa em C para reorganizar um dado array na seguinte ordem: menor, maior,
2o menor, 2o maior, 3o menor, 3o maior e assim por diante.

Exemplo:
> O array de entrada é:
5 8 1 4 2 9 3 7 6

> O novo array é:
1 9 2 8 3 7 4 6 5
*/

int* ordenaVetor(int *Array, int n){
  int menor=0,copia;
  for (int i = 0; i < n; i++) {
    menor = i;
    for (int j = i + 1; j < n; j++) {
      if (Array[j] < Array[menor]) {
        menor = j;
      }
    }
    copia = Array[i];
    Array[i] = Array[menor];
    Array[menor] = copia;
  }
  return Array;
}

void reordena(int *Array, int n) {
  int copia, menor = 0, meio;
  // Ordenar o vetor
  Array=ordenaVetor(Array, n);
  // criar vetor Auxiliar
  int vetAux[n];
  //copia os dados de vetor para o auxiliar
  for (int i = 0; i < n; i++) {
    vetAux[i] = Array[i];
  }
  meio=n/2;
  //faz os indices pares do vetor serem iguais aos primeiros elementos do vetor auxiliar
  for (int i = 0; i < meio; i++) {
    Array[i * 2] = vetAux[i];
  }
  if (n % 2 == 1) {
     meio=meio+1;
     Array[n-1]=vetAux[n-meio];
  }
  //faz os elementos impares do vetor serem iguais aos ultimos elementos do vetor auxiliar
  for (int i = 0; i < meio; i++) {
    Array[i * 2 + 1] = vetAux[n-1-i];
  }
  //mostrando o vetor após a modificaçãp
 for(int i=0;i<n;i++){
   printf("%d ",Array[i]);
 }
  printf("\n");
  //mostrando o vetor ordenado
  for(int i=0;i<n;i++){
    printf("%d ",vetAux[i]);
  }
}

int main(){

  int tamanho_array = 9;
  int array[] = { 5, 8, 1, 4, 2, 9, 3, 7, 6 };

  reordena( array, tamanho_array );

  return 0;
}