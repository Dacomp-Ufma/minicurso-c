#include <stdio.h>

/*
Crie um programa em C que receba um array de preços em que precos[i] é o preço de uma
determinada ação no i-ésimo dia.
Você deseja maximizar seu lucro escolhendo um único dia para comprar uma ação e escolher
um dia diferente no futuro para vender essa ação.

Retorne o lucro máximo que você pode obter com esta transação. Se você não conseguir
nenhum lucro, retorne 0.

Exemplo 1:
Entrada: preços = [7,1,5,3,6,4]
Saída: 5
Explicação: Compre no dia 2 (preço = 1) e venda no dia 5 (preço = 6), lucro = 6-1 = 5.
Observe que comprar no dia 2 e vender no dia 1 não é permitido porque você deve comprar
antes de vender.
*/

int lucroMaximo(int lista[], int n);
int maximo(int a, int b);

int main(){
    int tamanho_precos = 6;
    int precos[] = {7,1,5,3,6,4};
    printf("%d", lucroMaximo(precos, tamanho_precos));

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