#import "main.c"
#define SIZE 12

board TopPieces(board currentBoard)
{
    int x, y, greatestPiece, greatestLocation;
    int *yIterator;
    board tops = currentBoard;
    int *xIterator;

    xIterator = currentBoard.board;

    for(x = 0; x < SIZE; x++) {
        tops.board[x] = 0;
    }
    printf("%d", *xIterator);
    for(x = 0; x < SIZE; x++) {
        greatestPiece = *xIterator;
        greatestLocation = x;
        yIterator = xIterator + 1;
        for (y = x + 1; y < SIZE; y++) {
            if(*xIterator == *yIterator)
            {
                greatestPiece = *yIterator;
                greatestLocation = y;
            }
            yIterator = yIterator + 1;
        }
        tops.board[greatestLocation] = greatestPiece;
        xIterator++;
    }



    return tops;
}
