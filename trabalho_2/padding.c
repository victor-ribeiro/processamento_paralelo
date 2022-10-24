#include <stdio.h>
#include <stdlib.h>

#define N 10000

int main(){
    int lda = N + (16 - (N%16));
    float *vecA=(float*)malloc(lda * sizeof(float)), *vecB=(float*)malloc(lda * sizeof(float));
    float result=0;
    for (int i=0; i < N; i++){
        vecA[i] = 1.f;
        vecB[i] = 1.f;
    }
    for(int i=0; i<N; i++) result += vecA[i] * vecB[i];
    printf("%f\n", result);
    return 0;
}