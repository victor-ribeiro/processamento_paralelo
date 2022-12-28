#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// #include <omp.h>

#include "matriz.c"

void liberaMatriz(float* matriz);
void imprimeMatrix(float *mtx, int n);
float* alocaMatriz(int iTam);
void iniciaMatriz(int linhas, int colunas, float *matriz);
void copiaMatriz(float **mtxOrigem, float **mtxDestino);
float* transpose(float* mtx, int nrow, int ncol);
float* transpose_tile(float* mtx, int nrow, int ncol, int tile);
float* transpose_stride(float* mtx, int nrow, int ncol, int tile);
void transpose_MPI(int *mtx_, int ncols, int nrows, int rank, int tile, int threads);
float* transpose_paralel(float* mtx, int nrow, int ncol, int tile, int threads);
float enval(float *mtx, int cols, int rows);
float enval_tile(float *mtx, int cols, int rows, int tile);
float enval_paralel(float *mtx, int cols, int rows, int tile, int threads);
