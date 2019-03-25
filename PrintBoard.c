#include "board.h"
void PrintBoard(board currentBoard) {
    int i;
    printf("[ ");
    for (i = 0; i < SIZE; i++) {
        printf("%d", currentBoard.pieces[i]);
    }
    printf(" ]\n");
}