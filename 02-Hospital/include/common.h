#ifndef MINUCURSO_C_COMMON_H
#define MINUCURSO_C_COMMON_H

typedef struct solucao {
    int* solucao;
    int custo;
} solucao;

/* Auxiliares */
void trocar(int *n1, int *n2);
void permutar(int* array, int i, int pessoas, int* custo, solucao* sol);

/* Principal*/
solucao* execute(int quant, int* custo);

/* Funções de criação da matriz */
int* criar_matriz_custo_aleatoria(int tamanho);
int* import_from_file(char* path, int* ptr_tamanho);

/* Auxiliares da ui */
void print_matrix(int* matrix, int size);
void print_solucao(solucao* sol, int quant);
#endif //MINUCURSO_C_COMMON_H
