//Main code containing data types 
//Patrick O'Doherty
//Last updated: 3/14/19

typedef struct board {
    /*
    Boards are represented by a int array of size 12
    the first four positions are small pieces, 
    the first two being player one, and the 3rd and 4th being player 2
    this repeats for medium and large pieces
    */
    int board[11];
    int pieces; //number of pieces on board
    char playerTurn; //can be x or o
    int result; //win, lose, tie
} board;

/* 
canonicalBoards is an array of boards that we use to store boards that we've already visited
TODO: determine a size so we don't have to dynamically allocate space
*/
board canonicalBoards[11];

void main() {

    return;
}