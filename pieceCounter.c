#include "board.h"

int pieceCounter(board currentBoard) {
    int i, count = 0;

    for(i = 0; i < SIZE; i++) {
        if(currentBoard.pieces[i] > 0)
            count++;
    }

    return count;
}