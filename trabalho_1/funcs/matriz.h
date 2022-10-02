#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matriz.c"

#define origem 2

float *alocaVetor(int iTam);
void iniciaMatriz(int linhas, int colunas, float **matriz);
float **alocaMatriz(int iLinhas, int iColumas);
void liberaMatriz(float** matriz, int linhas);
void imprimirMatriz(float** fMatriz, int linhas, int colunas);
void copiaMatriz(float ***matriz_origem, float ***matriz_destino);
void transpose(float **mtx, float nrow, float ncol);
void enval(void (*ptr_f)(float**, float, float), float** mtx, float nrow, float ncol);