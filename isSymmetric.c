#pragma once
#include "board.h"

int symmetryMap[9][9] = {{1, 2, 3, 4, 5, 6, 7, 8, 9},
                         {7, 8, 9, 4, 5, 6, 1, 2, 3},
                         {3, 6, 9, 2, 5, 8, 1, 4, 7},
                         {9, 8, 7, 6, 5, 4, 3, 2, 1},
                         {7, 4, 1, 8, 5, 2, 9, 6, 3},
                         {9, 6, 3, 8, 5, 2, 7, 4, 1},
                         {3, 2, 1, 6, 5, 4, 9, 8, 7},
                         {1, 4, 7, 2, 5, 8, 3, 6, 9}};

board isSymmetric(board currentBoard, board **canonicalBoards, int canonicalSize)
{
    int x, y, z, isSymmetric;
    board symmetric;
    symmetric.result = -1;
    for(x = 0; x < canonicalSize; x++){
        for(y = 0; y < 8 && (*canonicalBoards)->playerTurn == currentBoard.playerTurn; y++){
            isSymmetric = 1;
            for(z = 0; z < 12; z += 2) {
                if (currentBoard.pieces[z] > 0 && currentBoard.pieces[z + 1] > 0) {
                    if (!(symmetryMap[y][currentBoard.pieces[z] - 1] == (*canonicalBoards)->pieces[z] ||
                          symmetryMap[y][currentBoard.pieces[z] - 1] == (*canonicalBoards)->pieces[z + 1]) &&
                        !(symmetryMap[y][currentBoard.pieces[z + 1] - 1] == (*canonicalBoards)->pieces[z] ||
                          symmetryMap[y][currentBoard.pieces[z + 1] - 1] == (*canonicalBoards)->pieces[z + 1])) {
                        isSymmetric = 0;
                        break;
                    }
                } else if (currentBoard.pieces[z] == 0 && currentBoard.pieces[z + 1] > 0){
                    if (!(symmetryMap[y][currentBoard.pieces[z + 1] - 1] == (*canonicalBoards)->pieces[z] ||
                          symmetryMap[y][currentBoard.pieces[z + 1] - 1] == (*canonicalBoards)->pieces[z + 1])) {
                        isSymmetric = 0;
                        break;
                    }
                } else if (currentBoard.pieces[z] > 0 && currentBoard.pieces[z + 1] == 0)
                {
                    if( !(symmetryMap[y][currentBoard.pieces[z] - 1] == (*canonicalBoards)->pieces[z] ||
                           symmetryMap[y][currentBoard.pieces[z] - 1] == (*canonicalBoards)->pieces[z + 1])){
                        isSymmetric = 0;
                        break;
                    }
                }
            }
            if(isSymmetric == 1)
                return *(*canonicalBoards);
        }
        (*canonicalBoards)++;

    }
    return symmetric;
}