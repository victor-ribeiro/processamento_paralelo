float* alocaVetor(int iTam){
    return (float*) malloc(iTam * sizeof(int));
}

float** alocaMatriz(int iLinhas, int iColumas){
    float** tmp = (float**) malloc(iLinhas * sizeof(float*));
    for(int i=0; i < iLinhas; i++) tmp[i] = alocaVetor(iColumas);
    return tmp;
}

void iniciaMatriz(int linhas, int colunas, float *matriz){
    int n = linhas * colunas;
    for(int i = 0; i < n; i++)
        matriz[i] = ((float) rand() / (float) RAND_MAX);
}

void liberaMatriz(float* matriz){
    free(matriz);
}

void transpose(float *mtx, int nrow, int ncol){
    // funcao com a troca direta, sem subdividir a matriz
    float* mtx_aux = alocaVetor(nrow * ncol);
    iniciaMatriz(nrow, ncol, mtx_aux);
    for (int i=0; i < nrow; i++)
        for (int j=0; j < ncol; j++)
            mtx[(i * nrow) + j] = mtx_aux[(j * ncol) + i];
    liberaMatriz(mtx_aux);
}

void transpose_t(float* mtx, int nrow, int ncol, int tile){
    float* mtx_aux = alocaVetor(nrow * ncol);
    iniciaMatriz(nrow, ncol, mtx_aux);
    for(int ii=0; ii < nrow; ii+=tile)
        for(int jj=0; jj < ncol; jj+=tile)
            for(int i=ii; i < (tile + ii); i++)
                for(int j=jj; j < (tile + jj); j++)
                    mtx[(i * nrow) + j]=mtx_aux[(j * ncol) + i];
    liberaMatriz(mtx_aux);
}

void enval(void (*ptr_f)(float*, int, int), float* mtx, int nrow, int ncol){
    double time_spent = 0.0;
    clock_t begin = time(NULL);
    ptr_f(mtx, nrow, ncol);
    clock_t end = time(NULL);
    time_spent += (end - begin);
    printf("%f ,", time_spent);
}

void enval_t(void (*ptr_f)(float*, int, int, int), float* mtx, int nrow, int ncol, int tile){
    double time_spent = 0.0;
    clock_t begin = time(NULL);
    ptr_f(mtx, nrow, ncol, tile);
    clock_t end = time(NULL);
    time_spent += (end - begin);
    printf("%f\n", time_spent);
}