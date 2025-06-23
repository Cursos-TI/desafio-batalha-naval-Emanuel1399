#include <stdio.h>

#define BOARD_SIZE 10
#define NAVIO 3      /* valor que representa qualquer parte de navio */

/* 0 = água; 3 = navio                                              */
int board[BOARD_SIZE][BOARD_SIZE] = {0};

/* --------- Funções de posicionamento --------------------------- */

/* Coloca um navio vertical (para baixo) de tamanho len,
   começando em (row, col).                                         */
void coloca_vertical(int row, int col, int len)
{
    for (int i = 0; i < len && row + i < BOARD_SIZE; i++)
        board[row + i][col] = NAVIO;
}

/* Coloca um navio horizontal (para a direita).                     */
void coloca_horizontal(int row, int col, int len)
{
    for (int j = 0; j < len && col + j < BOARD_SIZE; j++)
        board[row][col + j] = NAVIO;
}

/* Coloca um navio diagonal “↘” (descendo e indo à direita).        */
void coloca_diagonal_baixo_direita(int row, int col, int len)
{
    for (int k = 0; k < len &&
                    row + k < BOARD_SIZE &&
                    col + k < BOARD_SIZE; k++)
        board[row + k][col + k] = NAVIO;
}

/* Coloca um navio diagonal “↗” (subindo e indo à direita).         */
void coloca_diagonal_cima_direita(int row, int col, int len)
{
    for (int k = 0; k < len &&
                    row - k >= 0 &&
                    col + k < BOARD_SIZE; k++)
        board[row - k][col + k] = NAVIO;
}

/* --------- Exibição completa do tabuleiro ---------------------- */
void imprime_tabuleiro(void)
{
    puts("Tabuleiro (0 = água, 3 = navio):");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
            printf("%d ", board[i][j]);
        putchar('\n');
    }
}

int main(void)
{
    /* ------------------------------------------------------------
       Posições escolhidas a título de exemplo:
       - Diagonal ↘  tamanho 4  a partir de (0,0)
       - Diagonal ↗  tamanho 3  a partir de (9,0)
       - Vertical     tamanho 5  a partir de (2,4)
       - Horizontal   tamanho 3  a partir de (6,1)
       ------------------------------------------------------------ */
    coloca_diagonal_baixo_direita(0, 0, 4);
    coloca_diagonal_cima_direita (9, 0, 3);
    coloca_vertical(2, 4, 5);
    coloca_horizontal(6, 1, 3);

    imprime_tabuleiro();
    return 0;
}