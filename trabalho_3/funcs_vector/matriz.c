void imprimeMatrix(float *mtx, int n){
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++)
            printf("%f\t", mtx[(i * n) + j]);
        printf("\n");
    }
    printf("\n");
}

float* alocaMatriz(int iTam){
    // return (float*) malloc(iTam * sizeof(float));
    return aligned_alloc(64, sizeof(float) * iTam * 64);
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

float* transpose(float* mtx, int nrow, int ncol, int tile){
    float tam = nrow * ncol;
    float* mtx_aux = alocaMatriz(tam);
    #pragma simd
    for(unsigned ii=0; ii < nrow; ii+=tile)
        for(unsigned jj=0; jj < ncol; jj+=tile)
                for(unsigned i=ii; i < (tile + ii); i++)
                    #pragma vector aligned
                    for(unsigned j=jj; j < (tile + jj); j++)
                        mtx_aux[(j * ncol) + i] = mtx[(i * nrow) + j];        
    return mtx_aux;
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