#include <stdio.h>
#include <string.h>

#define TAM 5  // Tamanho fixo das matrizes de habilidade

// Zera todas as posições da matriz
void limpar_matriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            matriz[i][j] = 0;
}

// Exibe a matriz no console
void exibir_matriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Padrão: CONE
void habilidade_cone(int matriz[TAM][TAM]) {
    int meio = TAM / 2;
    for (int i = 0; i < TAM; i++) {
        for (int j = meio - i; j <= meio + i; j++) {
            if (j >= 0 && j < TAM)
                matriz[i][j] = 1;
        }
    }
}

// Padrão: CRUZ
void habilidade_cruz(int matriz[TAM][TAM]) {
    int meio = TAM / 2;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (i == meio || j == meio)
                matriz[i][j] = 1;
        }
    }
}

// Padrão: OCTAEDRO (diamante)
void habilidade_octaedro(int matriz[TAM][TAM]) {
    int meio = TAM / 2;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio)
                matriz[i][j] = 1;
        }
    }
}

int main() {
    int matriz[TAM][TAM];

    // Habilidade: CONE
    limpar_matriz(matriz);
    habilidade_cone(matriz);
    printf("Habilidade: CONE\n");
    exibir_matriz(matriz);

    // Habilidade: CRUZ
    limpar_matriz(matriz);
    habilidade_cruz(matriz);
    printf("Habilidade: CRUZ\n");
    exibir_matriz(matriz);

    // Habilidade: OCTAEDRO
    limpar_matriz(matriz);
    habilidade_octaedro(matriz);
    printf("Habilidade: OCTAEDRO\n");
    exibir_matriz(matriz);

    return 0;
}