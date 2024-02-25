#include <stdio.h>

int main(){

    int arr1[] = {1,2,2,1,3,4,5,6,5,6};

    int n = 10;
    int ctr;
    for(int i = 0; i < n; i++){
        ctr = 0;
        for(int j = 0, k = n; j < k + 1; j++){
            
            if(i != j){
                if(arr1[i] == arr1[j]){
                    ctr++;
                }
            }
        }

        if(ctr == 0){
            printf("%d ", arr1[i]);
        }
    }
}


//resposta: Todos os elementos únicos em arr1
// para cada posição do vetor o segundo "for" busca todos os elementos que são iguais ao elemento daquela
// posição i, tirando o proprio elemento da posição i (i != j), caso o contador permaneça zerado podemos
// considerar o elemento da posição i como único no vetor




