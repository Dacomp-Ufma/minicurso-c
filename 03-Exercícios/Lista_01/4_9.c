
#include <stdio.h>
#include <stdlib.h>
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
//questao 4.9
void questao49(int *vetor1,int *vetor2, int n1){
  int *vetor3=malloc(sizeof(int)*n1*2);
  for(int i=0;i<n1;i++){
    vetor3[i]=vetor1[i];
  }
  for(int i=n1;i<n1*2;i++){
    vetor3[i]=vetor2[i];
  }
  vetor3=ordenaVetor(vetor3,n1*2);
  float mediana=(vetor3[n1]+vetor3[n1-1])/2*1.0;
  printf("A mediana é: %f", mediana);

}
int main(){
  
}