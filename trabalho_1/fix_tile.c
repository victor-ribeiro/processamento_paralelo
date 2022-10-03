#include <stdio.h>
#include "funcs/matriz.h"

#define N_MAX 100000
#define tile 500

int main(){
    int n = (int) N_MAX / tile;
    printf("n, s_tile, tile\n");
    for(int i=1000; i <= N_MAX; i+=1000){
        int nrow=i, ncol=i;
        float *mtxA;
        mtxA = alocaVetor(nrow * ncol);
        iniciaMatriz(nrow, ncol, mtxA);
        printf("%d, ", i);
        enval((void (*) (float*, int, int)) transpose, mtxA, nrow, ncol);
        enval_t((void (*) (float*, int, int, int)) transpose_t, mtxA, nrow, ncol, tile);
        liberaMatriz(mtxA);
    }
    return 0;
}