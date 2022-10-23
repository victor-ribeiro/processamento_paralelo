#include <stdio.h>

#define n 1000

int main(){
    float mtxB[n], mtxA[n];
    for(int i=0; i<n; i++) mtxA[i] = 2;
    for (int i=0; i < n; i++)
        switch (i){
        case 0:
            mtxB[i] = 0.0f;
            break;
        case n-1:
            mtxB[i] = mtxA[i] + 1.f;
            break;
        default:
            mtxB[i] = 0.25f * (mtxA[i-1] + 2.0f * mtxA[i] + mtxA[i+1]);
            break;
        }
    for (int i=0; i < n; i++) printf("%f ", mtxB[i]);
    return 0;
}