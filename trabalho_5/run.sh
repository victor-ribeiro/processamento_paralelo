# docker run --rm -itv $(pwd):/home/app horovod/horovod /bin/bash -c "cd /home/app; nvcc --expt-relaxed-constexpr sobel.cu"
mpicc small_transpose.c && mpirun  -np 2 ./a.out 8 2 2
