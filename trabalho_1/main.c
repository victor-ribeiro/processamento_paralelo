#include <stdio.h>

#include "funcs/matriz.h"

int main(){
    int nrow=3, ncol=3;
    float **mtxA;
    mtxA = alocaMatriz(nrow, ncol);
    iniciaMatriz(nrow, ncol, mtxA);
    imprimirMatriz(mtxA, nrow, ncol);
    printf("transposicao\n");
    transpose(mtxA, nrow, ncol);
    imprimirMatriz(mtxA, nrow, ncol);
    return 0;
}
