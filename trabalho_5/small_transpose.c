#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mpi.h"

#include "funcs_vector/matriz.h"

int main(int argc, char **argv){
    const int N = atoi(argv[1]);
    const int TILE = atoi(argv[2]);
    const int THREADS = atoi(argv[3]);
    int rank, numtasks, tam;

    float *recvbuf, *mtx = alocaMatriz(N * N), *t_mtx = alocaMatriz(N*N);


    int n_sub_mtx, source=0;
    MPI_Status stat;
    MPI_Datatype indextype;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    tam = ceil(( N) / (numtasks - 1));

    // recvbuf = transpose_paralel(recvbuf, tam, tam, TILE, THREADS);
    n_sub_mtx = (int) ceil(sizeof(mtx) / tam * tam);

    if(rank == source) {
        int *blocklengths = (int*) malloc(sizeof(int) * n_sub_mtx);
        int *displacements = (int*) malloc(sizeof(int) * n_sub_mtx);
        iniciaMatriz(N,N, mtx);
        imprimeMatrix(mtx, N);

        for(int i = 0; i < n_sub_mtx; i++) blocklengths[i] = tam;
        for(int i = 0; i < n_sub_mtx; i++) {
            displacements[i] = tam * i;
            printf("[%d %d]\n", displacements[i], blocklengths[i]);
        }

        MPI_Type_indexed(n_sub_mtx, blocklengths, displacements, MPI_FLOAT, &indextype);
        MPI_Type_commit(&indextype);
        /*envio das mensagens*/
        for(int i = 1; i < numtasks; i++) MPI_Send(mtx, tam*tam, indextype, i, 1, MPI_COMM_WORLD);
    } 
    else{
        recvbuf = alocaMatriz(tam * tam);
        MPI_Recv(recvbuf, tam*tam, MPI_FLOAT, source, 1, MPI_COMM_WORLD, &stat);
        printf("rank= %d \n", rank);
        // imprimeMatrix(recvbuf, tam);
    }

    MPI_Finalize();
    return 0;
}