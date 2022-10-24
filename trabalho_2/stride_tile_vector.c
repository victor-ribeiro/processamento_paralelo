#include <stdio.h>
#include <stdlib.h>

#include "funcs_vector/matriz.h"

#define N 40960

int main(){
    float *mtxA = alocaMatriz(N * N);
    int tales[4] = {1024, 2048, 4096, 8192};
    iniciaMatriz(N, N, mtxA);
    printf("tile_size, transpose, transpose_stride;\n");
    for(int i=0; i < 4; i++){
        printf("%d,", tales[i]);
        enval_t((float* (*) (float*, int, int, int)) transpose, mtxA, N, N, tales[i]);
        printf(", ");
        enval_t((float* (*) (float*, int, int, int)) transpose_stride, mtxA, N, N, tales[i]);
        printf(";\n");
    }
    return 0;
}