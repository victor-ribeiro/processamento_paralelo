#define origem 2

float* alocaVetor(int iTam){
    return (float*) malloc(iTam * sizeof(int));
}

float** alocaMatriz(int iLinhas, int iColumas){
    float** tmp = (float**) malloc(iLinhas * sizeof(float*));
    for(int i=0; i < iLinhas; i++) tmp[i] = alocaVetor(iColumas);
    return tmp;
}

void iniciaMatriz(int linhas, int colunas, float **matriz){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = i < j ? 1: 0;
        }
    }
}

void liberaMatriz(float** matriz, int linhas){
    for(int i = 0; i < linhas; free(matriz[i++]));
    free(matriz);
}

void imprimirMatriz(float** fMatriz, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; printf("%8.4f ", fMatriz[i][j++]));
        printf("\n");
    }
}

void copiaMatriz(float ***matriz_origem, float ***matriz_destino){
    float **tmp = *matriz_origem;
//    *matriz_origem = *matriz_destino;
    *matriz_destino = tmp;
}

void transpose(float **mtx, float nrow, float ncol){
    // funcao com a troca direta, sem subdividir a matriz
    float** mtx_aux = alocaMatriz(nrow, ncol);
    iniciaMatriz(nrow, ncol, mtx_aux);
    for (int i=0; i < nrow; i++)
        for (int j=0; j < ncol; j++)
            mtx[i][j]=mtx_aux[j][i];
    liberaMatriz(mtx_aux, nrow);
}