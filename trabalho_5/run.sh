# docker run --rm -itv $(pwd):/home/app horovod/horovod /bin/bash -c "cd /home/app; nvcc --expt-relaxed-constexpr sobel.cu"
mpicc -fopenmp small_transpose.c && mpirun --allow-run-as-root -np 3 ./a.out 4 2 2
