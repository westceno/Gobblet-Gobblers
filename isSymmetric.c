#import "main.c"

const int symmetryMap[][] = {{3, 6, 9, 2, 5, 8, 1, 4, 7},
                             {9, 8, 7, 6, 5, 4, 3, 2, 1},
                             {7, 4, 1, 8, 5, 2, 9, 6, 3},
                             {9, 6, 3, 8, 5, 2, 7, 4, 1},
                             {3, 2, 1, 6, 5, 4, 9, 8, 7},
                             {1, 4, 7, 2, 5, 8, 3, 6, 9}};

int isSymmetric(board currentBoard, board *canonicalBoards, int canonicalSize)
{
    int x, y, z, isSymmetric;
    for(x = 0; x < canonicalSize; x++)
        for(y = 0; y < 9; y++) {
            isSymmetric = 1;
            for (z = 0; z < 6; z++)
                if (currentBoard.board[symmetryMap[y][z]] != canonicalBoards->board[symmetryMap[y][z]])
                    isSymmetric = 0;
            if (isSymmetric == 1)
                return isSymmetric;
        }
}