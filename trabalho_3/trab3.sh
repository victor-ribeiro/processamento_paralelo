#/bin/bash

gcc-12 -O3 -fopt-info-optimized-missed=vect_info.report -fopenmp transpose_openmp.c -o transpose.out

threads=2
rep=50
tam=40960
tile=1024

echo "gerando diferentes impleplementacoes"
for i in 1 2 3;
do
    ./transpose.out $i $threads $rep $tam $tile;
done

# echo "threads fixos"
# for i in 512 1024 2048 4096;
# do
#     ./transpose.out 2 $threads $rep $tam $i;
#     ./transpose.out 3 $threads $rep $tam $i;
# done

# echo "tile fixo"
# for i in 2 4 8 16
# do
#     ./transpose.out 3 $i $rep $tam $tile;
# done