#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa em C para encontrar a mediana de dois vetores ordenados de mesmo
tamanho
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

void mostra_mediana(int *vetor1, int *vetor2, int n1){
  int vetor3[2 * n1];
  for(int i=0;i<n1;i++){
    vetor3[i]=vetor1[i];
  }
  for(int i=n1;i<n1*2;i++){
    vetor3[i]=vetor2[i];
  }
  ordenaVetor(vetor3,n1*2);

  float mediana=(vetor3[n1]+vetor3[n1-1])/2*1.0;
  printf("A mediana é: %f", mediana);
}

int main(){
  int vetor_1[] = { 1, 2, 4, 5, 5, 9, 7, 6, 8 };
  int vetor_2[] = { 3, 4, 6, 6, 6, 9, 3, 1, 2 };
  int tamanho_vetor = 9;

  mostra_mediana( vetor_1, vetor_2, tamanho_vetor );
}