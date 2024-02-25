void MoveZerosProfinal(int *vetor, int n){
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
}

int main(){
  
}