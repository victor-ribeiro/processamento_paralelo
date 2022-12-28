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

    int rank, numtasks, n_cels, n_rows,source=0;
    float *mtx = alocaMatriz(N * N), *t_mtx = alocaMatriz(N * N);
    int *idx_mtx, *recvbuf, *sendbuf = (int*) malloc(sizeof(int) * n_cels);
    MPI_Request reqs[2];
    MPI_Status stats[2];

    idx_mtx = (int*) malloc(sizeof(int) * N * N);
    iniciaMatriz(N, N, mtx);

    for(int i = 0; i < N * N; i++) idx_mtx[i] = i;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    n_cels = (int) (N * N) / numtasks;
    n_rows = (int) N / numtasks;
    
    MPI_Scatter(idx_mtx, n_cels, MPI_INT, sendbuf, n_cels, MPI_INT, source, MPI_COMM_WORLD);
    recvbuf = (int*) malloc(sizeof(int) * n_cels);

    if (rank==0){
        double start = MPI_Wtime();
        transpose_MPI(sendbuf, N, n_rows, rank, TILE, THREADS);
        
        for(int i = 0; i < n_cels; i++) t_mtx[i] = mtx[sendbuf[i]];
        

        MPI_Irecv(recvbuf, n_cels, MPI_INT, 1, 1, MPI_COMM_WORLD, &reqs[0]);
        MPI_Wait(&reqs[0], &stats[0]);
        for(int i = n_cels; i < N*N; i++) t_mtx[i] = mtx[recvbuf[i-n_cels]];
        
        double end = MPI_Wtime();
        double time = end - start;
        printf("time: %f\n", time);
    }else{
        transpose_MPI(sendbuf, N, n_rows, n_rows, TILE, THREADS);
        MPI_Isend(sendbuf, n_cels, MPI_INT, 0, 1, MPI_COMM_WORLD, &reqs[1]);
    }

    // ainda falta coletar o tempo, 
    MPI_Finalize();
    liberaMatriz(mtx);
    return 0;
}