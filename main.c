//Main code containing data types 
//Patrick O'Doherty
//Last updated: 3/14/19

#include "main.h"


/* 
canonicalBoards is an array of boards that we use to store boards that we've already visited
TODO: determine a size so we don't have to dynamically allocate space
*/
board canonicalBoards[11];

void main() {
    int i, j;
    int candidateSize = 60;
    board currentBoard;
    board candidates[candidateSize];
   
    for (i = 0; i < SIZE; i++) { currentBoard.pieces[i] = 0; }

    Player_Turn(currentBoard);
    // currentBoard.pieces[0] = 1;
    // currentBoard.pieces[1] = 2;
    // currentBoard.pieces[4] = 4;
    // currentBoard.pieces[2] = 8;
    // currentBoard.pieces[11] = 2;
    // currentBoard.pieces[10] = 5;
    // for (i = 0; i < 60; i++) { for (j = 0; j < SIZE; j++ ) { candidates[i].pieces[j] = 0; }}
    // currentBoard.playerTurn = 0;    
    // // PrintBoard(currentBoard);

    // LegalMoves(currentBoard, candidates, 60);
    // // LegalMoves(candidates[0], candidates);
    // printf("%c\n", IsWinner(currentBoard));

    // for (i = 0; i < 60; i++) {
    //     // printf("\n%d: ", i);
    //     // PrintBoard(candidates[i]);
    // }
    // return;
}

