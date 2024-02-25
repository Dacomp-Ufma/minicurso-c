#include <stdio.h>

/*
Crie um programa em C para rotacionar à esquerda um array em n posições.
*/

void rotacionaVetor(int *Array, int n, int rotacoes){
  for(int i=0;i<rotacoes;i++){
      int save=Array[0];
      for(int i=0;i<n-1;i++){
        Array[i]=Array[i+1];
      }
      Array[n-1]=save;
  }
}

int main(){
  int array[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
  int tamanho_array = 9;
  int rotacoes = 3;

  rotacionaVetor( array, tamanho_array, rotacoes );
}