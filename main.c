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
    printf("test\n");
    board currentBoard;
    LegalMoves(currentBoard);
    return;
}