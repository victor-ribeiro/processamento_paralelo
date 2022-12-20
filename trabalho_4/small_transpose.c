#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs_vector/matriz.h"

int main(int argc, char *argv[]){
    const int N = atoi(argv[1]);
    const int TILE = atoi(argv[2]);
    const int THREADS = atoi(argv[3]);

    float *mtx = alocaMatriz(N * N);
    iniciaMatriz(N,N, mtx);
    imprimeMatrix(mtx, N);
    // transposicao sem otimizacao
    mtx = transpose(mtx, N, N);
    imprimeMatrix(mtx, N);

    // transposicao com tile
    mtx = transpose_tile(mtx, N, N, TILE);
    imprimeMatrix(mtx, N);
    
    // transposicao com openpm
    mtx = transpose_paralel(mtx, N, N, TILE, THREADS);
    imprimeMatrix(mtx, N);
    return 0;
}