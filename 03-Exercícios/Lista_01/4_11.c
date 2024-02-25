#include <stdio.h>

/*
Escreva um programa em C para mover todos os zeros para o final de um determinado vetor.
*/

void MoveZerosProFinal(int *vetor, int n){
  int vetAux[n];
  int cont=0;
  int qtdZeros=0;
  for(int i=0;i<n;i++){
    if(vetor[i]!=0){
      vetAux[cont]=vetor[i];
      cont++;
    }
    else{qtdZeros++;}
  }
  for(int i=0;i<n-qtdZeros;i++){
    vetor[i]=vetAux[i];
  }
  for(int i=n-qtdZeros;i<n;i++){
    vetor[i]=0;
  }
  for(int i=0;i<n;i++){
    printf("%d ", vetor[i]);
  }
  printf( "\n" );
}

int main(){
  int tamanho_vetor = 14;
  int vetor[] = { 1, 2, 3, 0, 0, 6, 0, 8, 5, 9, 0, 7, 6, 4 };

  MoveZerosProFinal( vetor, tamanho_vetor );
}