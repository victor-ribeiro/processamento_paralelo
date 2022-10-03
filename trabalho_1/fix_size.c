#include <stdio.h>
#include "funcs/matriz.h"

#define N_MAX 30000
#define MAX_TILE 10000

int main(){
    int nrow=N_MAX, ncol=N_MAX;
    printf("n, s_tile, tile\n");
    float **mtxA;
    mtxA = alocaMatriz(nrow, ncol);
    iniciaMatriz(nrow, ncol, mtxA);
    for(int i=1000; i <= MAX_TILE; i+=1000){
        printf("%d, ", i);
        enval((void (*) (float**, float, float)) transpose, mtxA, nrow, ncol);
        enval_t((void (*) (float**, float, float, int)) transpose_t, mtxA, nrow, ncol, i);
    }
    liberaMatriz(mtxA, nrow);
    return 0;
}