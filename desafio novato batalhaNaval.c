#include <stdio.h>

#define BOARD_SIZE 10

/* Representação de cada célula do tabuleiro:
   0 = água
   1 = parte do navio vertical
   2 = parte do navio horizontal
*/
int board[BOARD_SIZE][BOARD_SIZE] = {0};

/* Função de utilidade: marca um navio vertical de tamanho len
   cujo primeiro bloco fica em (row, col)              */
void coloca_navio_vertical(int row, int col, int len)
{
    for (int i = 0; i < len; i++)
    {
        board[row + i][col] = 1;          // 1 identifica “vertical”
    }
}

/* Função de utilidade: marca um navio horizontal de tamanho len
   cujo primeiro bloco fica em (row, col)              */
void coloca_navio_horizontal(int row, int col, int len)
{
    for (int j = 0; j < len; j++)
    {
        board[row][col + j] = 2;          // 2 identifica “horizontal”
    }
}

/* Percorre o tabuleiro e imprime as coordenadas de cada parte de navio */
void imprime_coordenadas_navios(void)
{
    printf("Coordenadas dos navios:\n");

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 1)
            {
                printf("  Navio vertical  -> (%d, %d)\n", i, j);
            }
            else if (board[i][j] == 2)
            {
                printf("  Navio horizontal -> (%d, %d)\n", i, j);
            }
        }
    }
}

int main(void)
{
    /* -------------------------
       1) Definimos posições fixas
          (poderiam vir do usuário
          – mas, no nível novato,
          deixamos no código)
       ------------------------- */
    coloca_navio_vertical(1, 2, 4);   // Começa em (1,2), tamanho 4, vai “para baixo”
    coloca_navio_horizontal(6, 5, 3); // Começa em (6,5), tamanho 3, vai “para a direita”

    /* 2) Mostramos as coordenadas  */
    imprime_coordenadas_navios();

    return 0;
}