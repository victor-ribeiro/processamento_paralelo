# docker run --rm -itv $(pwd):/home/app horovod/horovod /bin/bash -c "cd /home/app; nvcc --expt-relaxed-constexpr sobel.cu"
source /scratch/app/modulos/intel-psxe-2017.1.043.sh

mpicc -std=c99 -fopenmp small_transpose.c -o teste01.out
