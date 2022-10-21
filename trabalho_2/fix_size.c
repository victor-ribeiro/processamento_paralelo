#include <stdio.h>
#include "funcs/matriz.h"

#define N_MAX 20000

int main(){
    int nrow=N_MAX, ncol=N_MAX;
    printf("n, s_tile, tile\n");
    float *mtxA;
    int tiles[6] = {20000, 10000, 5000, 1000, 500, 250};
    mtxA = alocaVetor(nrow * ncol);
    iniciaMatriz(nrow, ncol, mtxA);
    for(int i=0; i < 6; i++){
        printf("%d, ", tiles[i]);
        enval((void (*) (float*, int, int)) transpose, mtxA, nrow, ncol);
        enval_t((void (*) (float*, int, int, int)) transpose_t, mtxA, nrow, ncol, tiles[i]);
    }
    liberaMatriz(mtxA);
    return 0;
}