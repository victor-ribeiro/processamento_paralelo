#/bin/bash

gcc-12 -O3 -fopt-info-optimized-missed=vect_info.report -fopenmp transpose_openmp.c -o transpose.out

threads=2
rep=3
tam=35000
tile=2500

echo "gerando diferentes impleplementacoes"
for i in 1 2 3;
do
    ./transpose.out $i $threads $rep $tam $tile;
done


echo "tile fixo"
for i in 2 4 8 16
do
    ./transpose.out 3 $i $rep $tam $tile;
done
