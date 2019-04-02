#include "main.h"

board canonicalBoards[2000000];

int Player_Turn(board currentBoard)
{
    board legalMoves[531441];

    board symmetricBoard;

    int totalMoves = 0, canonicalSize = 0, xWinnerCounter = 0, oWinnerCounter = 0, i, winner;

    if(IsWinner(currentBoard) == 'x' && currentBoard.playerTurn == 0)
        return 1;
    else if(IsWinner(currentBoard) == 'O' && currentBoard.playerTurn == 2)
        return 2;

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

    if(currentBoard.playerTurn == 0 && xWinnerCounter >= 1)
        return 1;
    else if(currentBoard.playerTurn == 0 && totalMoves == oWinnerCounter)
        return 2;
    else if(currentBoard.playerTurn == 2 && oWinnerCounter >= 1)
        return 2;
    else if(currentBoard.playerTurn == 2 && totalMoves == xWinnerCounter)
        return 1;
    else
        return 0;


}