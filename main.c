//Main code containing data types 
//Patrick O'Doherty
//Last updated: 3/14/19

#include "main.h"


/* 
canonicalBoards is an array of boards that we use to store boards that we've already visited
TODO: determine a size so we don't have to dynamically allocate space
*/

void main() {
    int i, j;
    int totalMoves;
    int candidateSize = 80;
    int result;
    board currentBoard;
    board candidates[candidateSize];
    malloc(sizeof(canonicalBoards) * 2);

    for (i = 0; i < SIZE; i++) { currentBoard.pieces[i] = 0; }
    printf("a\n");
    currentBoard.playerTurn = 'x';
    currentBoard.result = -1;
    result = Player_Turn(currentBoard);
    printf("Result of currentBoard: %d\n", result); 

    calloc(sizeof(canonicalBoards), 2);
    

    // currentBoard.pieces[0] = 1;
    // currentBoard.pieces[1] = 2;
    // currentBoard.pieces[4] = 4;
    // currentBoard.pieces[2] = 8;
    // currentBoard.pieces[11] = 2;
    // currentBoard.pieces[10] = 5;
    // for (i = 0; i < 60; i++) { for (j = 0; j < SIZE; j++ ) { candidates[i].pieces[j] = 0; }}
    // PrintBoard(currentBoard);

    // LegalMoves(currentBoard, candidates, &totalMoves);
    // // LegalMoves(candidates[0], candidates);
    // printf("%c\n", IsWinner(currentBoard));

    // for (i = 0; i < 60; i++) {
    //     // printf("\n%d: ", i);
    //     // PrintBoard(candidates[i]);
    // }
    // return;
}

