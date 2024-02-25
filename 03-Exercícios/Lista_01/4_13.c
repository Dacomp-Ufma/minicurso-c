//4,13
void EncontraSegundoMenorElemento(int **matriz,int n, int m){
  int menor=matriz[0][0],segundoMenor=matriz[0][0];
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(menor<matriz[i][j]){
          segundoMenor=menor;
          menor=matriz[i][j];
        }
        else if(matriz[i][j]<segundoMenor && matriz[i][j]!=menor){
          segundoMenor=matriz[i][j];
        }
      }
    }
  printf("O segundo menor elemento é: %d", segundoMenor);
}
int main(){
  
}