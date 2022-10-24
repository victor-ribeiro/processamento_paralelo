#include <stdio.h>
#include <stdlib.h>

#include "funcs_vector/matriz.h"

#define N 25000
#define tile 16384
int main(){
    float *mtxA = alocaMatriz(N * N);
    iniciaMatriz(N, N, mtxA);
    transpose(mtxA, N, N, tile);
    return 0;
}