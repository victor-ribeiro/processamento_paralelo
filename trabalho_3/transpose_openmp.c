#include<stdio.h>
#include<stdlib.h>
#include "funcs_vector/matriz.h"

#define N 40960
#define TILE 4096

int main(){
    float *mtx = alocaMatriz(N * N);
    iniciaMatriz(N, N, mtx);
    // imprimeMatrix(mtx, N);
    mtx = transpose(mtx,N, N, 2048);
    // imprimeMatrix(mtx, N);
    return 0;
}