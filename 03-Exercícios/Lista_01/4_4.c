#include <stdio.h>

int lucroMaximo(int lista[], int n);
int maximo(int a, int b);

int main(){

    int precos[] = {7,1,5,3,6,4};
    printf("%d", lucroMaximo(precos, 6));

}


int lucroMaximo(int lista[], int n){
    int minimo = lista[0];
    int memo[n];
    memo[0] = 0;
    for(int i = 1; i < n; i++){
        memo[i] = maximo(memo[i-1], lista[i] - minimo);
        if(lista[i] < minimo){
            minimo = lista[i];
        }
    }

    return memo[n-1];
}

int maximo(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}