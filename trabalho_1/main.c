#include <stdio.h>
#include "funcs/matriz.h"

#define n 30000

int main(){
    int nrow=n, ncol=n;
    float **mtxA;
    mtxA = alocaMatriz(nrow, ncol);
    iniciaMatriz(nrow, ncol, mtxA);
    // imprimirMatriz(mtxA, nrow, ncol);
    printf("transposicao\n");
    // imprimirMatriz(mtxA, nrow, ncol);
    enval((void (*) (float**, float, float)) transpose, mtxA, nrow, ncol);
    return 0;
}