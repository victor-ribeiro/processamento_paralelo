#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matriz.c"

float* alocaVetor(int iTam);
float** alocaMatriz(int iLinhas, int iColumas);
void iniciaMatriz(int linhas, int colunas, float *matriz);
void liberaMatriz(float* matriz);
void transpose(float *mtx, int nrow, int ncol);
void transpose_t(float* mtx, int nrow, int ncol, int tile);
void enval(void (*ptr_f)(float*, int, int), float* mtx, int nrow, int ncol);
void enval_t(void (*ptr_f)(float*, int, int, int), float* mtx, int nrow, int ncol, int tile);