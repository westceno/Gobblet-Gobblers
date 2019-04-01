#include "board.h"
#include "TopPieces.c"

void LegalMoves(board currentBoard, board* candidates, int* totalMoves) {

    int i, j, k, l; //loop increment
    int c; //count of candidate boards we've made
    int empty = 0; //flag to set if we've found an empty spot
    int handPieceSize;
    int boardPieceSize;

    board topPieces = TopPieces(currentBoard);
    board temp;
    //Create array of boards to hold all possible moves given currentBoard
    // board candidates[100];

    //Grab spare pieces. With those spare pieces, see if you can find a piece that has a 'height' greater our space.
    //So if we have a large piece we can place that over any piece other than another large one
    // i += 4 ensures that we're only looking at the current players pieces
    //0, 1, 4, 5, 8, 9 player 1
    //2, 3, 6, 7, 10, 11 player 2
    int currentPlayer = 0;

    for (i = 0; i < 60; i++) { for (j = 0; j < SIZE; j++ ) { candidates[i].pieces[j] = 0; }}

    for (i = currentPlayer; i < SIZE; i += 4) {
            // printf("c %d\n", c);
            // printf("i: %d\n", i);
            if (currentPlayer == 0) {
                handPieceSize = i % 3;
            } else if (currentPlayer == 2) {
                handPieceSize = (i - 2) % 3;
            }
            // printf("size: %d\n", handPieceSize);
        for (j = i; j <= i + 1; j++){
            
            // printf("j: %d\n", j);   
            // printf("valueJ: %d\n", currentBoard.pieces[j]); 

            handPieceSize = j % 3;

            // We've found a spare piece at pieces[i], now we must go through each position on the board (1-9)
            // and see if we can find a where we can move our spare to.
            // I would like to use top pieces for this purpose. I think top pieces needs to be made to return a 9 element int arrayidea

            //Loop through topPieces 9 times to see whats in each spot
            for (k = 1; k <= 9; k++) {
                for (l = 0; l < SIZE; l++) {
                    boardPieceSize = l % 3;
                    //if we've found a piece that is in position k on the top piece board, then the largest piece
                    //in position k is boardPieceSize
                    if (topPieces.pieces[l] == k) {
                        empty = 1; //flag that we've found a piece
                        if (handPieceSize > boardPieceSize) {
                            //move spare over the boardpiece (set the spare piece value to position k) add to candidate
                            empty = 1; 
                            temp = currentBoard;
                            temp.pieces[j] = k;
                            candidates[c++] = temp;
                            break;
                        }
                    }
                }
                //if we didn't find a piece at k, then move spare over empty space, and add to candidate
                if (empty == 0) {
                    temp = currentBoard; 
                    temp.pieces[j] = k;
                    candidates[c++] = temp;
                } else {empty = 0;}

            }
        }

    }

    //return the legalMoves array
    *totalMoves = c;
    return;
}