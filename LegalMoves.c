#include "board.h"
#define SIZE 12
board *LegalMoves(board currentBoard) {

    int i; //loop increment

    //Create array of boards to hold all possible moves given currentBoard
    board *candidates[25];

    //Grab spare pieces. With those spare pieces, see if you can find a piece that has a 'height' greater our space.
    //So if we have a large piece we can place that over any piece other than another large one
    for (i = currentBoard.playerTurn; i < SIZE; i += 4) {
        printf("i: %d\n", i);
        if (currentBoard.pieces[i] == 0) { //if a board's space value is 0, then it is a 'spare piece'
            //We've found a spare piece at pieces[i], now we must go through each position on the board (1-9)
            //and see if we can find a where we can move our spare to.
            //I would like to use top pieces for the purpose.
        }
    }

    //After this, loop through to find every possible move where you that involves moving one piece already on the board on top 
    //of another piece

    //return the legalMoves array
    return *candidates;
}