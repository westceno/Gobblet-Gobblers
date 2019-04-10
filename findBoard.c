#include "board.h"

 int findBoard(board currentBoard, board *canonicalBoards, int length)
 {
    int i, x, equivlent, position = 0;

    for(i = 0; i < length; i++) {
        equivlent = 1;
        if(currentBoard.playerTurn != canonicalBoards->playerTurn ||
            currentBoard.result != canonicalBoards->result)
            equivlent = 0;

        for(x = 0; x < SIZE && equivlent == 1; x++){
            if(currentBoard.pieces[x] != canonicalBoards->pieces[x])
                equivlent = 0;
        }

        if(equivlent == 1)
            return position;
        position++;
        canonicalBoards++;
    }

    return -1;
 }