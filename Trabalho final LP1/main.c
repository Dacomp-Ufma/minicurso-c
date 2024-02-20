#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
#include <time.h>
#include "funcoes.h"

int main() {
    srand(time(NULL));

    int flag = 1;

    Opcao opcao;
    MatrizCusto matrizCusto;

    // Loop
    while (flag) {
        // Menu
        printf("\nSelecione uma opção:\n");
        printf("1. Usar valores aleatórios para a matriz\n");
        printf("2. Escolher um arquivo de entrada\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao.tipo);

        switch (opcao.tipo) {
            case 1:
                // Opção para valores aleatórios
                printf("Digite o tamanho da matriz (número de enfermeiros e alas): ");
                scanf("%d", &opcao.entrada.tamanho);

                // Preencher a matriz com valores aleatórios
                matrizCusto.tamanho = opcao.entrada.tamanho;
                criarMatrizAleatoria(&matrizCusto);
                //flag = 0;
                break;

            case 2:
                // Opção para ler de um arquivo
                printf("Escolha o tamanho da matriz (10, 20, 30, 50, ou 100): ");
                scanf("%d", &opcao.entrada.tamanho);
                matrizCusto.tamanho = opcao.entrada.tamanho;

                // Construir o nome do arquivo com base no tamanho
                snprintf(opcao.entrada.nomeArquivo, sizeof(opcao.entrada.nomeArquivo), "D_%d.txt", opcao.entrada.tamanho);
              printf("%s", opcao.entrada.nomeArquivo);

                // Preencher a matriz com dados do arquivo
                criarMatrizDeArquivo(&matrizCusto, opcao.entrada.nomeArquivo);
                break;

            case 0:
                // Sair do programa
                flag = 0;
                return 0;

            default:
                // Opção inválida
                printf("Opção inválida. Tente novamente.\n");
        }


        // Se a opção for válida, continue com o algoritmo genético
        if (opcao.tipo >= 1 && opcao.tipo <= 2) {
            mostrarMatriz(&matrizCusto);
            executarAlgoritmo(&matrizCusto);
            liberarMatriz(&matrizCusto);
        }
    }

    return 0;
    system("pause");
}
