#include <stdio.h>

/*
Dado um array de n − 1 inteiros distintos no intervalo de 1 a n, crie um programa em C que
encontre o número que falta nele.

Exemplo:

Considerando o array arr = {1, 2, 3, 4, 5, 7, 8, 9, 10} cujos elementos são distintos e estão no
intervalo de 1 a 10. O número que falta é o 6.

Implemente a função:
int missing_number(arr[], int n);
*/

int missing_number(int arr[], int n);
int missing_number_Busca_binaria(int arr[], int n);

int main(){

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15};
    printf("%d", missing_number(arr, 15));
    printf("%d", missing_number_Busca_binaria(arr, 15));

}


//Essa primeira solução precisa percorrer N valores no pior caso (caso o elemento que falte seja o útimo)
// dizemos que essa solução tem O(n)
int missing_number(int arr[], int n){
    for(int i = 1; i <= n; i++){
        if(i == n){
            return n;
        }
        else{
            if(arr[i-1] != i){
                return i;
            }
        }
    }
}



//Essa segunda solução está aplicando o conceito de busca binária, já que a cada iteração desconsideramos metade do vetor,
// dizemos que é uma solução O(log n).
int missing_number_Busca_binaria(int arr[], int n){
    int esq = 0;
    int dir = n - 2;

    while(esq < dir){
        int meio = esq + ((dir - esq)/2);
        if(arr[meio] == meio + 1){
            esq = meio + 1;
        }
        else{
            dir = meio;
        }
    }

    return esq + 1;
    
}


