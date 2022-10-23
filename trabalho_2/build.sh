#!/bin/bash

echo 'Codigo nao vetorizado. '
gcc-12 -O3 -ftree-vectorize -fopt-info-vec -fopt-info-missed move_out_brancher.c
echo '\n\n'

echo 'Codigo vetorizado. '
gcc-12 -O3 -ftree-vectorize -fopt-info-vec -fopt-info-missed move_out_brancher_vec.c
