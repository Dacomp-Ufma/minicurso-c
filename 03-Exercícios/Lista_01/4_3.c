#define true 1
#define false 0
// Questão 4.3
// função que retorna se um elemento está no vetor
int EncontraElemento(int *Array, int elemento, int n) {
  for (int i = 0; i < n; i++) {
    if (Array[i] == elemento) {
      return true;
    }
  }
  return false;
}
// função que verifica qual numero falta
int NumeroQueFalta(int *Array, int n) {
  for (int i = 1; i < n; i++) { // de 1 até n
    // verifica se o elemento 1 não está no vetor, depois o 2 e assim
    // sucessivamente
    if (EncontraElemento(Array, i, n) == false) {
      // Se o elemento não estiver, retorna o elemento
      return i;
    }
  }

  return false;
}

int main(){

  
}