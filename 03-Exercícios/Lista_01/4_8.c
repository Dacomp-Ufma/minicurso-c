#include <stdio.h>

/*
Escreva um programa em C que subtraia dois vetores.
*/

void questao48(int *vetor1,int *vetor2, int n1, int n2){
  if(n1==n2){
    int vetor3[n1];
    for(int i=0;i<n1;i++){
      vetor3[i]=vetor1[i]-vetor2[i];
    }
  }

}
int main(){
  
}