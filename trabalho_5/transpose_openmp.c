#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "funcs_vector/matriz.h"

void escreveResult(float *buffer, char *nome, unsigned n){
    FILE *fp = fopen(nome, "wb");
    // fwrite(buffer, sizeof(buffer),n, fp);
    for(unsigned i=0; i < n; i++) fprintf(fp, "%f\n", buffer[i]);
    // fputs((char*) buffer, fp);
    fclose(fp);
}

int main(int argc, char *argv[]){
    // argumentos para a execucao do codigo
    const int OP = atoi(argv[1]);
    const int THREADS = atoi(argv[2]);
    const int REPETS = atoi(argv[3]);
    const int N = atoi(argv[4]);
    const int TILE = atoi(argv[5]);


    float *buffer = (float*) malloc(REPETS * sizeof(int));

    switch (OP){
    case 1:
        printf("TRANSPOSE\n");
        for(unsigned i=0; i < REPETS; i++){
            float *mtx = alocaMatriz(N * N);
            printf("Alocando valores (%d/%d):", i+1, REPETS);
            iniciaMatriz(N, N, mtx);
            printf(" invertendo");
            buffer[i] = enval(mtx, N, N);
            printf(" %f\n", buffer[i]);
        }
        escreveResult(buffer, "transpose.txt", REPETS);
        break;
    case 2:
        printf("TRANSPOSE TILE\n");
        for(unsigned i=0; i < REPETS; i++){
            float *mtx = alocaMatriz(N * N);
            printf("Alocando valores (%d/%d):", i+1, REPETS);
            iniciaMatriz(N, N, mtx);
            printf(" invertendo");
            buffer[i] = enval_tile(mtx, N, N, TILE);
            printf(" %f\n", buffer[i]);
        }
        escreveResult(buffer, "tile.txt", REPETS);
        break;
    case 3:
        printf("TRANSPOSE PARALLEL\n");
        for(unsigned i=0; i < REPETS; i++){
            float *mtx = alocaMatriz(N * N);
            printf("Alocando valores (%d/%d):", i+1, REPETS);
            iniciaMatriz(N, N, mtx);
            printf(" invertendo");
            buffer[i] = enval_paralel(mtx, N, N, TILE, THREADS);        
            printf(" %f\n", buffer[i]);
        }
        escreveResult(buffer, "threads.txt", REPETS);
        break;
    default:
        break;
    }
    return 0;
}