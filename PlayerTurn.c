#include "main.h"
#include "stdlib.h"
#include "findBoard.c"


board canonicalBoards[2000000];
board legalMoves[531441];

int canonicalSize = 0;

int Player_Turn(board currentBoard)
{
    malloc(sizeof(legalMoves) * 2);

    board symmetricBoard;

    int totalMoves = 0, xWinnerCounter = 0, oWinnerCounter = 0;
    int i, winner;

    if(IsWinner(currentBoard) == 'x' && currentBoard.playerTurn == 'x') {
        canonicalBoards[findBoard(currentBoard, canonicalBoards, canonicalSize)].result = 1;
        return 1;
    } else if(IsWinner(currentBoard) == 'o' && currentBoard.playerTurn == 'o') {
        canonicalBoards[findBoard(currentBoard, canonicalBoards, canonicalSize)].result = 2;
        return 2;
    }
    LegalMoves(currentBoard, legalMoves, &totalMoves);

    for( i = 0; i < totalMoves; i++){
        symmetricBoard = isSymmetric(legalMoves[i], canonicalBoards, canonicalSize);
        if( symmetricBoard.result == -1){
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
    }

   //printf("Canonical Size: %d\n", canonicalSize);
    if(currentBoard.playerTurn == 'x' && xWinnerCounter >= 1) {
        canonicalBoards[findBoard(currentBoard, canonicalBoards, canonicalSize)].result = 1;
        return 1;
    } else if(currentBoard.playerTurn == 'x' && totalMoves == oWinnerCounter) {
        canonicalBoards[findBoard(currentBoard, canonicalBoards, canonicalSize)].result = 2;
        return 2;
    } else if(currentBoard.playerTurn == 'o' && oWinnerCounter >= 1) {
        canonicalBoards[findBoard(currentBoard, canonicalBoards, canonicalSize)].result = 2;
        return 2;
    } else if(currentBoard.playerTurn == 'o' && totalMoves == xWinnerCounter) {
        canonicalBoards[findBoard(currentBoard, canonicalBoards, canonicalSize)].result = 1;
        return 1;
    } else {
        canonicalBoards[findBoard(currentBoard, canonicalBoards, canonicalSize)].result = 0;
        return 0;
    }

}