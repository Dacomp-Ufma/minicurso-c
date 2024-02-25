#include <stdio.h>

/*
Escreva um programa para encontrar o maior sub-vetor com número igual de 0s e 1s.

ex.:
vetor : 0 1 0 0 1 1 0 1 1 1
saída: sub-vetor encontrado do índice 0 ao 7
*/

int main(){

    int vetor[] = {0, 1, 0, 0, 1, 1, 0, 1, 1, 1};
    int n = sizeof(vetor)/sizeof(vetor[0]);

    int numeros0, numeros1, inicio, final, maiorSeq, seq;
    maiorSeq = 0;
    for(int i = 0; i < n; i++){
        numeros0 = 0;
        numeros1 = 0;
        seq = 0;
        if(n - i <= maiorSeq){
            break;
        }
        for(int j = i; j < n; j ++){
            if(vetor[j] == 0)
                numeros0++;
            else
                numeros1++;

            if(numeros0 == numeros1){
                seq = j - i + 1;
                if(seq > maiorSeq){
                    maiorSeq = seq;
                    inicio = i;
                    final = j;
                }
            }
               
        }
    }

    printf("%d %d", inicio, final);
}



