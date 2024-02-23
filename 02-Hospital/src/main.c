// Usa permutação para encontrar qual o menor caminho entre as alas e os enfermeiros/pessoas
#include <stdio.h>
#include "common.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// The main gadgetothing where all happens
int main() {
    int *custo = NULL, loop = true, temp;
    char buffer[20];
    solucao* sol = NULL;

    // Adiciona uma seed no rng
    srand(time(NULL));

    while(loop) {
        // If you change your mind, I'm the first in line
        // Honey, I'm still free, take a chance on me
        if (custo) {
           free(custo);
        }
        if (sol) {
            free(sol->solucao);
            free(sol);
        }


        // Menuzão topperson
        printf("\nSelecione uma opção:\n");
        printf("1. Usar valores aleatórios para a matriz\n");
        printf("2. Escolher um arquivo de entrada\n");
        printf("*. Sair\n");
        printf("Opção: ");
        fgets(buffer, sizeof(buffer), stdin);
        switch (atoi(buffer)) {
            case 1:
                // Opção para valores aleatórios
                printf("Digite o tamanho da matriz (número de enfermeiros e alas): ");
                fgets(buffer, sizeof(buffer), stdin);

                temp = atoi(buffer);

                if (temp < 1) {
                    printf("Valor inválido!\n");
                    // Temos que limpar o stdin
                    while (getchar() != '\n');
                    break;
                }

                // Preencher a matriz com valores aleatórios
                custo = criar_matriz_custo_aleatoria(temp);

                print_matrix(custo, temp);

                // Executar o algoroido
                sol = execute(temp, custo);

                // Imprime na tela pra galera saber
                print_matrix(custo, temp);
                print_solucao(sol, temp);

                printf("Aperte enter para continuar");
                fgets(buffer, sizeof(buffer), stdin);
                break;
            case 2:
                printf("Digite o nome do arquivo para importar: ");
                fgets(buffer, sizeof(buffer), stdin);

                // Remove o \n no fim, pra não mexer no path
                buffer[strcspn(buffer, "\n")] = 0;
                custo = import_from_file(buffer, &temp);

                print_matrix(custo, temp);

                if (custo == NULL) {
                    printf("Arquivo não existe");
                    break;
                }

                // Executar o algoroido
                sol = execute(temp, custo);

                // Imprime na tela pra galera saber
                print_matrix(custo, temp);
                print_solucao(sol, temp);

                printf("Aperte enter para continuar");
                fgets(buffer, sizeof(buffer), stdin);
                break;
            default:
                loop = false;
                break;
        }
    }
    return 0;
}
