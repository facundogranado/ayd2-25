#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define BOARD_SIZE 4
#define CELL_MAX (BOARD_SIZE * BOARD_SIZE - 1)
void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int cell = 0;

    print_sep(BOARD_SIZE);
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(BOARD_SIZE);
    }
}

char get_winner(char board[BOARD_SIZE][BOARD_SIZE]) {
    char winner = '-';

    // Verificar filas
    for (int row = 0; row < BOARD_SIZE && winner == '-'; ++row) {
        bool row_winner = true;
        for (int col = 1; col < BOARD_SIZE && row_winner; ++col) {
            if (board[row][col] != board[row][0] || board[row][0] == '-') {
                row_winner = false;
            }
        }
        if (row_winner) {
            winner = board[row][0];
        }
    }

    // Verificar columnas
    if (winner == '-') {
        for (int col = 0; col < BOARD_SIZE && winner == '-'; ++col) {
            bool col_winner = true;
            for (int row = 1; row < BOARD_SIZE && col_winner; ++row) {
                if (board[row][col] != board[0][col] || board[0][col] == '-') {
                    col_winner = false;
                }
            }
            if (col_winner) {
                winner = board[0][col];
            }
        }
    }

    // Verificar diagonal principal
    if (winner == '-') {
        bool diagonal1_winner = true;
        for (int i = 1; i < BOARD_SIZE && diagonal1_winner; ++i) {
            if (board[i][i] != board[0][0] || board[0][0] == '-') {
                diagonal1_winner = false;
            }
        }
        if (diagonal1_winner) {
            winner = board[0][0];
        }
    }

    // Verificar diagonal secundaria
    if (winner == '-') {
        bool diagonal2_winner = true;
        for (int i = 1; i < BOARD_SIZE && diagonal2_winner; ++i) {
            if (board[i][BOARD_SIZE - i - 1] != board[0][BOARD_SIZE - 1] || board[0][BOARD_SIZE - 1] == '-') {
                diagonal2_winner = false;
            }
        }
        if (diagonal2_winner) {
            winner = board[0][BOARD_SIZE - 1];
        }
    }

    return winner;
}


bool has_free_cell(char board[BOARD_SIZE][BOARD_SIZE])
{
    bool free_cell=false;
    for (int row = 0; row < BOARD_SIZE; row++){
        for (int column = 0; column < BOARD_SIZE; column++){
            if(board[row][column]=='-'){
                free_cell=true;
            }
        }
    }
    
    return free_cell;
}

int main(void)
{
    char board[BOARD_SIZE][BOARD_SIZE];
    
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int column = 0; column < BOARD_SIZE; column++) {
            board[row][column] = '-';
        }
    }
    
    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / BOARD_SIZE;
            int colum = cell % BOARD_SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
