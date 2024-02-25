#include <stdio.h>

/*
Dado um array de tamanho n, encontre o elemento majoritário. O elemento majoritário é o
elemento que aparece mais de b(n/2)c vezes. Você pode assumir que o array não está vazio e
que o elemento majoritário sempre existe no array.

Exemplo:
Entrada: [2, 1, 2]
Retorno: 2 que ocorre 2 vezes que é maior que 3/2.
*/

int elementoMajoritario(int lista[], int n);

int main() {
    int lista[] = {2, 1, 2, 2, 3, 5, 3, 7, 9, 3, 4, 3};
    printf("%d\n", elementoMajoritario(lista, 12));

    return 0;
}

int elementoMajoritario(int lista[], int n) {
    int freq[n];

    // Inicializa todos os elementos de freq com 1
    for (int i = 0; i < n; i++) {
        freq[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (freq[i] != 0) {
            int cont = 1;
            for (int j = i + 1; j < n; j++) {
                if (lista[i] == lista[j]) {
                    cont += 1;
                    freq[j] = 0;
                }
            }
            freq[i] = cont;
        }
    }

    int majoritario = 0;

    for (int i = 1; i < n; i++) {
        if (freq[i] > freq[majoritario]) {
            majoritario = i;
        }
    }

    return lista[majoritario];
}
