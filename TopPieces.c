#define SIZE 12
int *TopPieces(int *currentBoard)
{
    int x, y, greatestPiece, greatestLocation;
    int *yIterator;
    static int topPieces[SIZE];
    int *xIterator;

    xIterator = currentBoard;

    for(x = 0; x < SIZE; x++) {
        topPieces[x] = 0;
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
        topPieces[greatestLocation] = greatestPiece;
        xIterator++;
    }

    return topPieces;
}
