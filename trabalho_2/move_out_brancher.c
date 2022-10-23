#include <stdio.h>

#define n 1000

int main(){
    float mtxB[1000], mtxA[1000];
    for (int i=0; i < n-1; i++)
        if(n==0) mtxB[i] = 0.0f;
        else if(n==n-1) mtxB[i] = mtxA[i] + 1.f;
        else mtxB[i] = 0.25f * (mtxA[i-1] + 2.0f * mtxA[i] + mtxA[i+1]);
    return 0;
}