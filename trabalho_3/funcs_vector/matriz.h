#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matriz.c"

void imprimeMatrix(float *mtx, int n);
float* alocaMatriz(int iTam);
void iniciaMatriz(int linhas, int colunas, float *matriz);
void copiaMatriz(float **mtxOrigem, float **mtxDestino);
float* transpose(float* mtx, int nrow, int ncol, int tile);
void enval_t(float* (*ptr_f)(float*, int, int, int), float* mtx, int nrow, int ncol, int tile);