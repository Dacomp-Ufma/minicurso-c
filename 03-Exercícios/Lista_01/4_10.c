#include <stdio.h>

int absoluto(int n);

int main(){
    int vetor[] = {38, 44, 63, -51, -35, 19, 84, -69, 4, -46};
    int elemento1 = vetor[0];
    int elemento2 = vetor[1];

    int maisProximo = vetor[0] + vetor[1];
    for(int i = 0; i < (sizeof(vetor)/4); i ++){
        for(int j = i + 1; j < (sizeof(vetor)/4); j++){
            int soma = vetor[i] + vetor[j];
            if(absoluto(soma) < absoluto(maisProximo)){
                maisProximo = soma;
                elemento1 = vetor[i];
                elemento2 = vetor[j];
            }

        }
    }

    printf("%d %d", elemento1, elemento2);

}

int absoluto(int n){
    if(n < 0){
        return n * -1;
    }

    return n;
}

