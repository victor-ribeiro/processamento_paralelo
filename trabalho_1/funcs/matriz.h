#define origem 2

float* alocaVetor(int iTam){
    return (float*) malloc(iTam * sizeof(int));
}

void iniciaMatriz(int linhas, int colunas, float** matriz_controle, float **matriz_destino){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz_destino[i][j] = i < j ? 1: 0;
        }
    }
}

float** alocaMatriz(int iLinhas, int iColumas){
    float** tmp = (float**) malloc(iLinhas * sizeof(int*));
    for(int i=0; i < iLinhas; i++) tmp[i] = alocaVetor(iColumas);
    return tmp;
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

void transpose(){
    return ;
}
