#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>


void trocar(int *n1, int *n2) {
    assert(n1 && n2);
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

solucao* new_solucao(int quant_pessoas) {
    solucao* temp = (solucao*)malloc(sizeof(solucao));
    assert(temp);
    temp->custo = INT_MAX;
    temp->solucao = (int*)malloc(sizeof(int)*quant_pessoas);
    assert(temp->solucao);
    return temp;
}

void permutar(int* array, int i, int pessoas, int* custo, solucao* sol) {
    // Permuta todo mundo
    // quando encontrar, verifica se o custo é menor
    assert(array && custo && sol);
    if (i == pessoas) {
        int val_custo = 0;
        // Achei um permutado - Calcula o custo
        for (int j = 0; j < pessoas; j++) {
            int t = j * pessoas + array[j];
            val_custo += custo[j * pessoas + (array[j] - 1)]; 
        }

        // Troca a seleção se necessário
        if (val_custo < sol->custo) {
            for (int j = 0; j < pessoas; j++) {
                sol->solucao[j] = array[j];
                sol->custo = val_custo;
            }
        }
    } else {
        // Permuta pra todo mundo
        for (int j = i; j <= pessoas - 1; j++) {
            trocar(&array[i], &array[j]);
            permutar(array, i+1, pessoas, custo, sol);
            trocar(&array[i], &array[j]);
        }
    }
}

solucao* execute(int quant, int* custo) {
    // O algoritmo
    assert(custo);

    // Monta um array pra ter todas as possíveis seleções
    int* array = (int*)malloc(sizeof(int)*quant);
    assert(array);

    for (int i = 0; i < quant; i++) {
        array[i] = i+1;
    }

    // Solução que vai ser retornada
    solucao* sol = new_solucao(quant);
    assert(sol);

    permutar(array, 0, quant, custo, sol);
    

    free(array);

    return sol;
}

/*
 * Cria uma matriz a partir de números aleatórios de 1 a 100
*/
int* criar_matriz_custo_aleatoria(int tamanho){
    int* matriz = (int*)malloc(sizeof(int) * (tamanho * tamanho));
    assert(matriz);

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            // rand() % 100 retorna o resto da divisão do número aleatório do rng por 100 - Sempre é de 0 a 100
            matriz[i * tamanho + j] = (rand() % 100);
        }
    }

    return matriz;
}

/*
 * Importa a matriz de um arquivo - Parser não implementado por falta de tempo para explicar
*/
int* import_from_file(char* path, int* ptr_tamanho) {
    assert(path);
    int tamanho;
    FILE* arquivo = fopen(path, "r");

    // Esse erro pode acontecer em prod - Por isso não foi substituído por um assert
    if (arquivo == NULL) {
        printf("arquivo foi de base");
        return NULL;
    }

    // Lê o início do arquivo para saber o tamanho
    fscanf(arquivo, "%d", &tamanho);

    // Cria a matriz pra retorno
    int* matriz = (int*)malloc(sizeof(int) * (tamanho * tamanho));
    assert(matriz);

    // Pega todos os valores do arquivo
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            fscanf(arquivo, "%d", &matriz[i * tamanho + j]);
        }
    }

    // Lembre-se de limpar tudo o que alocou
    fclose(arquivo);
    *ptr_tamanho = tamanho; 
    return matriz;
}


/*                               Auxiliares da UI                                       */
void print_matrix(int* matrix, int size) {
    assert(matrix);
    printf("Matriz: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i * size + j]);
        }
        printf("\n");
    }
}

void print_solucao(solucao* sol, int quant) {
    assert(sol);
    printf("Solução: \n");
    for (int i = 0; i < quant; i++) {
        printf("Pessoa = %d, Ala = %d\n", i+1, sol->solucao[i]);
    }
    printf("custo: %d\n", sol->custo);
}