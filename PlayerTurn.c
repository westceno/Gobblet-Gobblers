#include "main.h"


int Player_Turn(board currentBoard)
{
    board legalMoves[1000];
    board canonicalBoards[10000];
    board symmetricBoard;

    int totalMoves = 0, canonicalSize = 0, xWinnerCounter = 0, oWinnerCounter = 0, x, winner;

    if(IsWinner(currentBoard) == 'x' && currentBoard.playerTurn == 0)
        return 1;
    else if(IsWinner(currentBoard) == '0' && currentBoard.playerTurn == 2)
        return 2;

    //TODO We need to get a size from legal moves so lets pass
    // in a pointer to a size count also legal moves should change turn counter
    LegalMoves(currentBoard, legalMoves, &totalMoves);

    for( x = 0; x < totalMoves; x++){
        symmetricBoard = isSymmetric(legalMoves[x], canonicalBoards, canonicalSize);
        if( symmetricBoard.result == -1){
            canonicalBoards[canonicalSize] = legalMoves[x];
            winner = Player_Turn(legalMoves[x]);
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