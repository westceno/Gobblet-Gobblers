#pragma once

#define SIZE 12
#define BOARD_SIZE 9 //3x3
#define P1 0
#define P2 2

typedef struct board {
    /*
    Boards are represented by a int array of size 12 (pieces)
    the first four positions are small pieces, 
    the first two being player one, and the 3rd and 4th being player 2
    this repeats for medium and large pieces
    */
<<<<<<< HEAD
    int pieces[SIZE];
    int playerTurn; //can be x (0) or o (2)
=======
    int pieces[12];
    char playerTurn; //can be x or o
>>>>>>> 633ff8af81559fa3fdd237f0ffe630c634a55efc
    int result; //win, lose, tie
} board;