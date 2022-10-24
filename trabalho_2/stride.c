#include <stdio.h>
#include <stdlib.h>

#define STRIP 1024
#define N 10000

int main(){
    const int nPrime = N - (N%STRIP);
    float *vecA=(float*) malloc(N * sizeof(float)), *vecB=(float*) malloc(N * sizeof(float));
    float result = 0;
    for(int i=0; i < N; i++){
        vecA[i] = 1;
        vecB[i] = 1;
    }
    for(int ii = 0; ii < nPrime; ii += STRIP)
        for(int i=ii; i < ii+STRIP; i++)
            result += vecA[i] * vecB[i];
    for(int i = nPrime; i < N; i++) result += vecA[i] * vecB[i];
    printf("%f\n", result);
    return 0;
}