#include "board.h"
#include "TopPieces.c"


int findWinner(char one, char two, char three) {
    if (one == two && two == three) {
        return 1;
    }
    return 0;
}

char IsWinner(board currentBoard) {

    int i, j, k;
    char pos[9]; //int array to put 'x' or 'o' in with topPiece data
    int empty = 0;

    board topPieces = TopPieces(currentBoard);

    // PrintBoard(currentBoard);
    // PrintBoard(topPieces);
    
    //Put 'x' in pos array

    for (k = 1; k <= BOARD_SIZE; k++) {
        // printf("%d", k);
        for (i = P1; i < SIZE; i += 4) {
            for (j = i; j <= i+1; j++) {
                if (topPieces.pieces[j] == k) {
                    empty = 1;
                    pos[k-1] = 'x';
                }
            }
        }
        if (empty == 0) {
            pos[k-1] = '_';
        } else { empty = 0; }
    }

    //Put 'o' in pos array
    empty = 0;
    for (k = 1; k <= BOARD_SIZE; k++) {
        // printf("%d", k);
        if (pos[k-1] != 'x') {
            for (i = P2; i < SIZE; i += 4) {
                for (j = i; j <= i+1; j++) {
                    if (topPieces.pieces[j] == k) {
                        empty = 1;
                        pos[k-1] = 'o';
                    }
                }
            }
            if (empty == 0 ) {
                pos[k-1] = '_';
            } else { empty = 0; }
        }
    }

    //print out the pos board (debug)

    // for (i = 0; i < BOARD_SIZE; i++) {
    //     if (i % 3 == 0 && i != 0) { printf("\n");}
    //     printf("%c", pos[i]);
    // }
    // printf("\n");

    //check for winner

    //check rows 
    for (i = 0; i < BOARD_SIZE; i += 3) {
        if (findWinner(pos[i], pos[i+1], pos[i+2]) == 1) {
            return pos[i];
        }
    }

    //check columns 
    for (i = 0; i < BOARD_SIZE; i++) {
        if (findWinner(pos[i], pos[i+3], pos[i+6]) == 1) {
            return pos[i];
        }
    }

    //check diagonals
    if (findWinner(pos[0], pos[4], pos[8]) == 1) {
        return pos[0];
    }
    if (findWinner(pos[2], pos[4], pos[6]) == 1) {
        return pos[0];
    }

}