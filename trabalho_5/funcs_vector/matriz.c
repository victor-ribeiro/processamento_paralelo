void imprimeMatrix(float *mtx, int n){
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++)
            printf("%f\t", mtx[(i * n) + j]);
        printf("\n");
    }
    printf("\n");
}

void liberaMatriz(float* matriz){
    free(matriz);
}

float* alocaMatriz(int iTam){
    return (float*) malloc(sizeof(float) * iTam);
}

void iniciaMatriz(int linhas, int colunas, float *matriz){
    // essa funcao nao consegue vetoriza
    int n = linhas * colunas;
    for(int i = 0; i < n; i++)
        matriz[i] = ((float) rand() / (float) RAND_MAX);
}

void copiaMatriz(float **mtxOrigem, float **mtxDestino){
    float *tmp = *mtxOrigem;
    *mtxOrigem = *mtxDestino;
    *mtxDestino = tmp;
}

float* transpose(float* mtx, int nrow, int ncol){
    int tam = nrow * ncol;
    float* mtx_aux = alocaMatriz(tam);
    for(int i=0; i < nrow; i++)
        for(int j=0; j < ncol; j++)
            mtx_aux[(i * nrow) + j] = mtx[(j * ncol) + i];
    liberaMatriz(mtx);
    return mtx_aux;
}

float* transpose_tile(float* mtx, int nrow, int ncol, int tile){
    int tam = nrow * ncol;
    float* mtx_aux = alocaMatriz(tam);
    for(unsigned ii=0; ii < nrow; ii+=tile)
        for(unsigned jj=0; jj < ncol; jj+=tile)
            for(unsigned i=ii; i < (tile + ii); i++)
                for(unsigned j=jj; j < (tile + jj); j++)
                    mtx_aux[(i * nrow) + j] = mtx[(j * ncol) + i];
    liberaMatriz(mtx);
    return mtx_aux;
}

void transpose_MPI(int *mtx_, int ncols, int nrows, int rank, int tile, int threads){
    // omp_set_num_threads(threads);
    for(unsigned ii=0; ii < nrows; ii+=tile)
        for(unsigned jj=0; jj < ncols; jj+=tile)
            // #pragma omp parallel for
            for(unsigned i=ii; i < (tile + ii); i++)
                // #pragma simd
                for(unsigned j=jj; j < (tile + jj); j++)
                    mtx_[i * ncols + j] = j * ncols + i + rank;
}

// float* transpose_paralel(float* mtx, int nrow, int ncol, int tile, int threads){
//     int tam = nrow * ncol;
//     float* mtx_aux = alocaMatriz(tam);
//     omp_set_num_threads(threads);
//     for(unsigned ii=0; ii < nrow; ii+=tile)
//         for(unsigned jj=0; jj < ncol; jj+=tile)
//             #pragma omp parallel for
//             for(unsigned i=ii; i < (tile + ii); i++)
//                 #pragma simd
//                 for(unsigned j=jj; j < (tile + jj); j++){
//                     mtx_aux[(i * nrow) + j] = mtx[(j * ncol) + i];
//                 }
//     liberaMatriz(mtx);
//     return mtx_aux;
// }

// float enval(float *mtx, int cols, int rows){
//     clock_t begin = time(NULL);
//     float * tmp = transpose(mtx, rows, cols);
//     clock_t end = time(NULL);
//     float time = end - begin;
//     free(tmp);
//     return time;
// }

// float enval_tile(float *mtx, int cols, int rows, int tile){
//     clock_t begin = time(NULL);
//     float * tmp = transpose_tile(mtx, rows, cols, tile);
//     clock_t end = time(NULL);
//     float time = end - begin;
//     free(tmp);
//     return time;
// }

// float enval_paralel(float *mtx, int cols, int rows, int tile, int threads){
//     clock_t begin = time(NULL);
//     float * tmp = transpose_paralel(mtx, rows, cols, tile, threads);
//     clock_t end = time(NULL);
//     float time = end - begin;
//     free(tmp);
//     return time;
// }