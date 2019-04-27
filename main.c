#include "main.h"


/* 
canonicalBoards is an array of boards that we use to store boards that we've already visited
TODO: determine a size so we don't have to dynamically allocate space
*/

void main() {
    int i, j;
    int totalMoves;
    int result;
    board currentBoard;
    malloc(sizeof(canonicalBoards) * 2);

    for (i = 0; i < SIZE; i++) { currentBoard.pieces[i] = 0; }
    printf("a\n");
    currentBoard.playerTurn = 'x';
    currentBoard.result = -2;
    canonicalBoards[0] = currentBoard;
    canonicalSize++;
    result = Player_Turn(currentBoard);
    printf("Result of currentBoard: %d\n", result);
    printAsAList();

    free(canonicalBoards);

    return; 0;

}