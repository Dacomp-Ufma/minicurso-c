#include <stdio.h>

/*
Escreva um programa em C para verificar se um número é um palíndromo ou não
*//

int main() {
    int num, reverso = 0, original, resto;

    // Entrada do usuário
    printf("Digite um número: ");
    scanf("%d", &num);

    original = num;

    // Calcula o número reverso
    while (num > 0) {
        resto = num % 10;
        reverso = reverso * 10 + resto;
        num /= 10;
    }

    // Verifica se o número é um palíndromo
    if (original == reverso) {
        printf("%d é um número palíndromo.\n", original);
    } else {
        printf("%d não é um número palíndromo.\n", original);
    }

    return 0;
}
