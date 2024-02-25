#include <stdio.h>

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
