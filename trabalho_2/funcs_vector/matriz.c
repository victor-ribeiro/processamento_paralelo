float* alocaMatriz(int iTam){
    return (float*) malloc(iTam * sizeof(int));
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
    // *mtxDestino = tmp;
}

void liberaMatriz(float* matriz){
    free(matriz);
}

float* transpose(float* mtx, int nrow, int ncol, int tile){
    float tam = nrow * ncol;
    float* mtx_aux = alocaMatriz(tam);
    copiaMatriz(&mtx_aux, &mtx);
    for(int ii=0; ii < nrow; ii+=tile)
        for(int jj=0; jj < ncol; jj+=tile)
            for(int i=ii; i < (tile + ii); i++)
                for(int j=jj; j < (tile + jj); j++)
                    mtx[(i * nrow) + j] = mtx_aux[(j * ncol) + i];
    return mtx;
}

float* transpose_stride(float* mtx, int nrow, int ncol, int tile){
    int primeRow = nrow - (nrow % 512);
    int primeCol = nrow - (ncol % 512);
    float tam = nrow * ncol;
    float* mtx_aux = alocaMatriz(tam);
    copiaMatriz(&mtx_aux, &mtx);
    for(int ii=0; ii < primeRow; ii+=tile){
        for(int jj=0; jj < primeCol; jj+=tile){
            for(int i=ii; i < (tile + ii); i++)
                for(int j=jj; j < (tile + jj); j++){
                    mtx[(i * primeRow) + j] = mtx_aux[(j * primeCol) + i];
            }
        }
    }
    for(int i = primeRow; i < nrow; i++)
        for(int j = primeCol; j < ncol; j++)
                mtx[(i * nrow) + j] = mtx_aux[(j * ncol) + i];
    return mtx;
}

void enval_t(float* (*ptr_f)(float*, int, int, int), float* mtx, int nrow, int ncol, int tile){
    double time_spent = 0.0;
    float *tmp;
    clock_t begin = time(NULL);
    tmp = ptr_f(mtx, nrow, ncol, tile);
    clock_t end = time(NULL);
    time_spent += (end - begin);
    printf("%f", time_spent);
}