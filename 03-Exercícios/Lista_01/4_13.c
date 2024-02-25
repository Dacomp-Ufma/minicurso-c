#include <stdio.h>

#define N 4
#define M 3

/*
Escreva um programa em C para encontrar o segundo menor elemento em uma matriz.
*/

void EncontraSegundoMenorElemento( int **matriz, int n, int m ){
    int menor=matriz[0][0],segundoMenor=matriz[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if ( matriz[i][j] < menor ){
                segundoMenor=menor;
                menor = matriz[i][j];
            } else if ( matriz[i][j] < segundoMenor && matriz[i][j] != menor ){
                segundoMenor = matriz[i][j];
            }
        }
    }
    printf("O segundo menor elemento é: %d", segundoMenor);
}

int main(){
    int matriz[ N ][ M ] = {
        { 1, 2, 3 },
        { 9, 8, 7 },
        { 4, 5, 6 },
        { 10, 12, 11 }
    };

    EncontraSegundoMenorElemento( matriz, N, M );
}