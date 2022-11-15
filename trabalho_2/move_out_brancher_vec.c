#include <stdio.h>
#include <stdlib.h>
#define n 1000

int main(){
    // _mm_malloc é da arquitetura x86.
    float *mtxB=(float*) malloc(n*sizeof(float)), *mtxA=(float*) malloc(n*sizeof(float));
    for(int i=0; i<n; i++){
        mtxA[i] = 1.0f;
        mtxB[i] = 0.0f;
    }
    mtxB[0] = 0.0f;
    for (int i=1; i < n-1; i++){
        mtxB[i] = 0.25 * (mtxA[i-1] + 2.0 * mtxA[i] + mtxA[i+1]);
    }
    mtxB[n-1] = mtxA[n-1] + 1.f;
    for (int i=0; i < n; i++) printf("%f ", mtxB[i]);
}
