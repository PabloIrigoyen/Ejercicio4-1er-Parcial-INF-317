#include "stdio.h"
#include "stdlib.h"
#include "omp.h"

void multiplicar_matriz_vector(int **matriz, int *vector, int *resultado, int N) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        resultado[i] = 0;
        for (int j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }
}

int main() {
    int N;

    printf("Ingrese la dimension de la matriz cuadrada: ");
    scanf("%d", &N);

    int **matriz = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        matriz[i] = (int *)malloc(N * sizeof(int));
    }

    int *vector = (int *)malloc(N * sizeof(int));
    int *resultado = (int *)malloc(N * sizeof(int));

    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Ingrese los elementos del vector:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &vector[i]);
    }

    multiplicar_matriz_vector(matriz, vector, resultado, N);
    printf("Matriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Vector:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    printf("Resultado:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        free(matriz[i]);
    }
    free(matriz);
    free(vector);
    free(resultado);

    return 0;
}
