#include "main.h"
#include "stdlib.h"

void printAsAList() {
    int i, x;
    FILE *file;
    file = fopen("gobblet_Output.txt", "w");

    for(i = 0; i < canonicalSize; i++) {
        fprintf(file, "%d:[", i);
        for(x = 0; x < canonicalBoards[i].nextSize; x++){
            if(x != canonicalBoards[i].nextSize - 1)
                fprintf(file, "%d,", canonicalBoards[i].next[x]);
            else
                fprintf(file, "%d", canonicalBoards[i].next[x]);
        }

        fprintf(file, "]");
        if(i != canonicalSize - 1)
            fprintf(file, ",");
    }
}

