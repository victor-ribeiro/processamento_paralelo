#!/bin/bash

clang -O3 -Rpass=loop-vectorize -Rpass-missed=loop-vectorize -Rpass-analysis=loop-vectorize stride_tile_vector.c -o stride.exe

for i in 1 2 3 4 5 6 7 8 9 10;
    do 
        ./stride.exe >> stride_$i.txt;
    done

cd ..
git add .
git commit -m "arquivos de resultado"
git push
