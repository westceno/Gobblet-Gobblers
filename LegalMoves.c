#include "board.h"
#include "TopPieces.c"

char switchPlayer(char currentPlayer) {
    if (currentPlayer == 'x') {
        return 'o';
    } else {
        return 'x';
    }
}

void LegalMoves(board currentBoard, board* candidates, int* totalMoves) {

    int i, j, k, l; //loop increment
    int c = 0; //count of candidate boards we've made
    int empty = 0; //flag to set if we've found an empty spot
    int handPieceSize;
    int boardPieceSize;

    board topPieces = TopPieces(currentBoard);
    board temp;
    //Create array of boards to hold all possible moves given currentBoard
    // board candidates[100];

    //Grab spare pieces. With those spare pieces, see if you can find a piece that has a 'height' greater our space.
    //So if we have a large piece we can place that over any piece other than another large one
    //i += 4 ensures that we're only looking at the current players pieces
    //0, 1, 4, 5, 8, 9 player 1
    //2, 3, 6, 7, 10, 11 player 2

    for (i = 0; i < 80; i++) { for (j = 0; j < SIZE; j++ ) { candidates[i].pieces[j] = 0; }}
    
    if (currentBoard.playerTurn == 'x') {
        i = 0;
    } else if (currentBoard.playerTurn == 'o') {
        i = 2;
    }

    for (i; i < SIZE; i += 4) {
        for (j = i; j <= i + 1; j++){
            handPieceSize = j / 4;

            // We've found a spare piece at pieces[i], now we must go through each position on the board (1-9)
            // and see if we can find a where we can move our spare to.
            // I would like to use top pieces for this purpose. I think top pieces needs to be made to return a 9 element int arrayidea

            //Loop through topPieces 9 times to see whats in each spot
            for (k = 1; k <= 9; k++) {
                for (l = 0; l < SIZE; l++) {
                    boardPieceSize = l / 4;
                    //if we've found a piece that is in position k on the top piece board, then the largest piece
                    //in position k is boardPieceSize
                    if (topPieces.pieces[l] == k) {
                        empty = 1; //flag that we've found a piece
                        if (handPieceSize > boardPieceSize) {
                            //move spare over the boardpiece (set the spare piece value to position k) add to candidate
                            empty = 1; 
                            temp = currentBoard;
                            temp.pieces[j] = k;
                            temp.result = -2;
                            temp.playerTurn = switchPlayer(temp.playerTurn);
                            candidates[c++] = temp;
                            break;
                        }
                    }
                }
                //if we didn't find a piece at k, then move spare over empty space, and add to candidate
                if (empty == 0) {
                    temp = currentBoard; 
                    temp.pieces[j] = k;
                    temp.result = -2;
                    temp.playerTurn = switchPlayer(temp.playerTurn);
                    candidates[c++] = temp;
                } else {empty = 0;}

            }
        }

    }

    //return the legalMoves array
    *totalMoves = c;
    return;
}