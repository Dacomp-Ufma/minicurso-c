
#define SOLUCAO(tamanho) (tamanho*tamanho)

// Definindo uma estrutura para representar a matriz de custos
typedef struct {
    int **dados;
    int tamanho;
} MatrizCusto;

// Definindo uma união para representar diferentes tipos de entrada
typedef union {
    int tamanho;          // Para valores aleatórios
    char nomeArquivo[20];  // Para arquivos
} Entrada;

// Definindo uma estrutura para representar uma opção do menu
typedef struct {
    int tipo;          // 1 para valores aleatórios, 2 para arquivos
    Entrada entrada;
} Opcao;

// Função para liberar a memória da matriz
void liberarMatriz(MatrizCusto *matriz) {
    if (matriz->dados != NULL) {
        for (int i = 0; i < matriz->tamanho; i++) {
            if(matriz->dados[i] != NULL)
            free(matriz->dados[i]);
        }
        free(matriz->dados);
    }
}

// Função para liberar a memória de solução
void liberarSolucoes(int tamanho, int **solucao) {
    if (solucao != NULL) {
        for (int i = 0; i < SOLUCAO(tamanho); i++) {
            if (solucao[i] != NULL) {
                free(solucao[i]);
            }
        }
        free(solucao);
        solucao = NULL;  // Definindo o ponteiro como NULL após a liberação
    }
}

// Função para criar uma matriz de custos com valores aleatórios
void criarMatrizAleatoria(MatrizCusto *matriz) {
    matriz->dados = (int **)malloc(matriz->tamanho * sizeof(int *));
    if (matriz->dados == NULL) {
        printf("Erro ao alocar memória para a matriz.\n");
        exit(1);
    }
    for (int i = 0; i < matriz->tamanho; i++) {
        matriz->dados[i] = (int *)malloc(matriz->tamanho * sizeof(int));
        if (matriz->dados[i] == NULL) {
            printf("Erro ao alocar memória para a matrizCusto.\n");
            exit(1);
        }
        for (int j = 0; j < matriz->tamanho; j++) {
            matriz->dados[i][j] = (rand() % 100);
        }
    }
}

// Função para criar uma matriz de custos a partir de um arquivo
int criarMatrizDeArquivo(MatrizCusto *matriz, const char *nomeArquivo) {
    // Abrir arquivo para leitura
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; // Retorna um código de erro
    }

    // Alocar memória para a matriz de custos
    matriz->dados = (int **)malloc(matriz->tamanho * sizeof(int *));
    if(matriz->dados == NULL) {
      printf("Erro ao alocar memória para a matriz.\n");
      return 1;}
    for (int i = 0; i < matriz->tamanho; i++) {
        matriz->dados[i] = (int *)malloc(matriz->tamanho * sizeof(int));
      if(matriz->dados[i] == NULL) {
        printf("Erro ao alocar memória para a matriz.\n");
        return 1;
      }
    }
    // Ler a matriz de custos do arquivo
    printf("\nLendo matriz do arquivo %s...\n", nomeArquivo);

    int buff;
    fscanf(arquivo, "%d", &buff);
    for (int i = 0; i < matriz->tamanho; i++) {
        for (int j = 0; j < matriz->tamanho; j++) {
            fscanf(arquivo, "%d", &matriz->dados[i][j]);
        }
    }
    fclose(arquivo);
    return 0; // Retorna 0 para indicar sucesso
}

void mostrarSolucoes(int tamanho, int **solucao) {
    for (int i = 0; i < SOLUCAO(tamanho); i++) {
        printf("\nSolucão %d: ", i + 1);
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", solucao[i][j]);
        }
        printf("\n");
    }
}


// Função para criar soluções
void inicializarSolucao(int tamanho, int **solucao) {
    for (int i = 0; i < SOLUCAO(tamanho); i++) {
        solucao[i] = (int *)malloc(tamanho * sizeof(int));
        if(solucao[i] == NULL){
            printf("Erro ao alocar memória para a solucao.\n");
            exit(1);
        }
        for (int j = 0; j < tamanho; j++) {
            solucao[i][j] = j;
        }

        // Embaralhar as alas para criar uma atribuição aleatória
        for (int j = tamanho - 1; j > 0; j--) {
            int k = rand() % (j + 1);
            int temp = solucao[i][j];
            solucao[i][j] = solucao[i][k];
            solucao[i][k] = temp;
        }
    }
    //mostrarSolucoes(tamanho, solucao);
}

// Função para calcular o custo de uma atribuição
int calcularCusto(MatrizCusto *matriz, int atribuicao[]) {
    int custo = 0;
    for (int i = 0; i < matriz->tamanho; i++) {
        custo += matriz->dados[i][atribuicao[i]];
    }
    return custo;
}

// Função para realizar o algoritmo
void executarAlgoritmo(MatrizCusto *matriz) {
    int melhorAtribuicao[matriz->tamanho];
    int melhorCusto = INT_MAX;

    int **solucao = (int **)malloc(SOLUCAO(matriz->tamanho) * sizeof(int *));
    if (solucao == NULL) {
        printf("Erro ao alocar memória para a solucao.\n");
        exit(1);
    }

    inicializarSolucao(matriz->tamanho, solucao);

    for (int i = 0; i < SOLUCAO(matriz->tamanho); i++) {
        int custo = calcularCusto(matriz, solucao[i]);
        if (custo < melhorCusto) {
            melhorCusto = custo;
            for (int j = 0; j < matriz->tamanho; j++) {
                melhorAtribuicao[j] = solucao[i][j];
            }
        }
    }

    printf("Atribuição otimizada:\n");
    for (int i = 0; i < matriz->tamanho; i++) {
        printf("Enfermeiro %d -> Ala %d\n", i + 1, melhorAtribuicao[i] + 1);
    }
    printf("Custo total: %d\n", melhorCusto);

    liberarSolucoes(matriz->tamanho, solucao);

    printf("\nResultado.\n");
}


// Função para exibir a matriz
void mostrarMatriz(MatrizCusto *matriz) {
    printf("Matriz de Custos:\n");
    for (int i = 0; i < matriz->tamanho; i++) {
        for (int j = 0; j < matriz->tamanho; j++) {
            printf("%d\t", matriz->dados[i][j]);
        }
        printf("\n");
    }
}