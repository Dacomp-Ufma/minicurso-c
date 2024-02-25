#include<stdio.h>
#include<stdlib.h>
int TemnoVetor(int *Array, int n , int elemento){
  int cont=0;

  for(int i=0;i<n;i++){
    if(Array[i]==elemento){
      cont++;
    }
  }
  return cont;
}

void qtdRepetidos(int n){
  int *vetor=(int*)malloc(sizeof(int)*n);
  for(int i=0;i<n;i++){
    scanf("%d", &vetor[i]);
  }
  int repetidos[n];
  for(int i=0;i<n;i++){
    repetidos[i]=0;
  }
  int qtd=0;
  for(int i=0;i<n;i++){
    if(TemnoVetor(vetor, n, vetor[i])>1 && TemnoVetor(repetidos, n, vetor[i])<1){
      repetidos[i]=vetor[i];
      qtd++;
    }
  }

  printf("A quantidade de números repetidos é: %d", qtd);
}

int main(){
  qtdRepetidos(6);
}