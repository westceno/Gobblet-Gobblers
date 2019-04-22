#include "main.h"
#include "stdlib.h"
#include "findBoard.c"


board canonicalBoards[200000];


int canonicalSize = 0;
int legalSize = 4000;

int Player_Turn(board currentBoard)
{

    board *legalMoves;

    legalMoves = malloc((legalSize)* sizeof(board*));

    board symmetricBoard;

    int totalMoves = 0, xWinnerCounter = 0, oWinnerCounter = 0, cycleCounter = 0, currentLocation = 0, currentNextSize = 0;
    int i, x, winner;

    currentLocation = findBoard(currentBoard, canonicalBoards, canonicalSize);

    for(x = 0; x < 81; x++)
        canonicalBoards[currentLocation].next[x] = -1;

    if(IsWinner(currentBoard) == 'x' && currentBoard.playerTurn == 'x') {

        canonicalBoards[currentLocation].result = 1;

        return 1;
    } else if(IsWinner(currentBoard) == 'o' && currentBoard.playerTurn == 'o') {
        canonicalBoards[currentLocation].result = 2;
        return 2;
    }


    LegalMoves(currentBoard, legalMoves, &totalMoves);


    for( i = 0; i < totalMoves; i++){
        //printf("total Moves %d\n", totalMoves);
        symmetricBoard = isSymmetric(legalMoves[i], canonicalBoards, canonicalSize);
        if( symmetricBoard.result == -1){
            canonicalBoards[currentLocation].next[currentNextSize] = canonicalSize;
            currentNextSize++;
            canonicalBoards[canonicalSize] = legalMoves[i];
            canonicalSize++;
            winner = Player_Turn(legalMoves[i]);
        }
        else if (symmetricBoard.result != -1) {
            winner = symmetricBoard.result;
        }

        if(winner == 1)
            xWinnerCounter++;
        else if(winner == 2)
            oWinnerCounter++;
        else
            cycleCounter++;
    }

    canonicalBoards[currentLocation].nextSize = currentNextSize;
    free(legalMoves);
   //printf("Canonical Size: %d\n", canonicalSize);
   //printf("x = %d y = %d\n", xWinnerCounter,oWinnerCounter);
    if(currentBoard.playerTurn == 'x' && xWinnerCounter >= 1) {
        canonicalBoards[currentLocation].result = 1;
        return 1;
    } else if(currentBoard.playerTurn == 'x' && totalMoves == oWinnerCounter + cycleCounter) {
        canonicalBoards[currentLocation].result = 2;
        return 2;
    } else if(currentBoard.playerTurn == 'o' && oWinnerCounter >= 1) {
        canonicalBoards[currentLocation].result = 2;
        return 2;
    } else if(currentBoard.playerTurn == 'o' && totalMoves == xWinnerCounter + cycleCounter) {
        canonicalBoards[currentLocation].result = 1;
        return 1;
    } else {
        canonicalBoards[currentLocation].result = 0;
        return 0;
    }

}