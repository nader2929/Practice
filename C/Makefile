CC      = gcc
CFLAGS  = -g -Werror
RM      = rm -f


default: all

all: num_to_text matrix_multiplication

num_to_text: num_to_text.c
	$(CC) num_to_text.c $(CFLAGS) -o bin/num_to_text

matrix_multiplication: matrix_multiplication.c
	$(CC) matrix_multiplication.c $(CFLAGS) -o bin/matrix_multiplication

clean veryclean:
	$(RM) num_to_text