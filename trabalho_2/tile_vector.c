#include <stdio.h>
#include <stdlib.h>

#include "funcs_vector/matriz.h"

#define N 40000
#define tile 5000

int main(){
    float *mtxA = alocaMatriz(N * N);
    iniciaMatriz(N, N, mtxA);
    int tales = {250, 500, 1000, 2500, 5000, 10000};
    for(int i=0; i < 6; i++)
        enval_t((float* (*) (float*, int, int, int)) transpose_stride, mtxA, N, N, tales[i]);
    return 0;
}