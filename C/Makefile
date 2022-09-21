CC      = gcc
MPICC   = mpicc
CFLAGS  = -g -Werror -lm
RM      = rm -f


default: all

all: num_to_text matrix_multiplication parallel_matrix_multiplication

num_to_text: num_to_text.c
	$(CC) num_to_text.c $(CFLAGS) -o bin/num_to_text

matrix_multiplication: matrix_multiplication.c
	$(CC) matrix_multiplication.c $(CFLAGS) -o bin/matrix_multiplication

parallel_matrix_multiplication: parallel_matrix_multiplication.c
	$(MPICC) parallel_matrix_multiplication.c $(CFLAGS) -o bin/parallel_matrix_multiplication

gaussian_blur: gaussian_blur.c
	$(CC) gaussian_blur.c $(CFLAGS) -o bin/gaussian_blur

clean veryclean:
	$(RM) bin/num_to_text bin/matrix_multiplication bin/parallel_matrix_multiplication