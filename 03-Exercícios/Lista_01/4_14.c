int* rotacionaVetor(int *Array, int n, int rotacoes){
  for(int i=0;i<rotacoes;i++){
      int save=Array[0];
      for(int i=0;i<n-1;i++){
        Array[i]=Array[i+1];
      }
      Array[n-1]=save;
  }
  return Array;
}

int **criaMatriz(int n, int m){
  int **matriz=(int**)malloc(sizeof(int*)*n);
  for(int i=0;i<n;i++){
    matriz[i]=malloc(sizeof(int)*m);
  }

  return matriz;
}

int main(){
  
}