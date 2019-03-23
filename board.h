#pragma once
typedef struct board {
    /*
    Boards are represented by a int array of size 12 (pieces)
    the first four positions are small pieces, 
    the first two being player one, and the 3rd and 4th being player 2
    this repeats for medium and large pieces
    */
    int pieces[12];
    char playerTurn; //can be x or o
    int result; //win, lose, tie
} board;