#include <stdio.h>

#define n 1000

int main(){
    float mtxB[n], mtxA[n];
    for(int i=0; i<n; i++){
        mtxA[i] = 1;
        mtxB[i] = 0;
    }
    
    mtxB[0] = 0.0f;
    #pragma clang loop vectorize(enable)
    for (int i=1; i < n-1; i++)
        mtxB[i] = 0.25f * (mtxA[i-1] + 2.0f * mtxA[i] + mtxA[i+1]);
    mtxB[n-1] = mtxA[n-1] + 1.f;
    for (int i=0; i < n; i++) printf("%f ", mtxB[i]);
}