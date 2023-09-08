CC      = g++
MPICC   = mpicc
CFLAGS  = -g -Werror -lm
RM      = rm -rf
BIN_FOLDER = if [ ! -d "./bin" ]; then mkdir bin; fi
HELPERS_FOLDER = helpers/*.cpp

default: all

all: num_to_text matrix_multiplication parallel_matrix_multiplication gaussian_blur

num_to_text: num_to_text.cpp
	$(BIN_FOLDER)
	$(CC) num_to_text.cpp $(HELPERS_FOLDER) $(CFLAGS) -o bin/num_to_text

matrix_multiplication: matrix_multiplication.cpp
	$(BIN_FOLDER)
	$(CC) matrix_multiplication.cpp $(HELPERS_FOLDER) $(CFLAGS) -o bin/matrix_multiplication

thread_matrix_multiplication: thread_matrix_multiplication.cpp
	$(BIN_FOLDER)
	$(CC) thread_matrix_multiplication.cpp $(HELPERS_FOLDER) $(CFLAGS) -o bin/thread_matrix_multiplication

gaussian_blur: gaussian_blur.cpp
	$(BIN_FOLDER)
	$(CC) gaussian_blur.cpp $(HELPERS_FOLDER) $(CFLAGS) -o bin/gaussian_blur

recursive_file_extractor: recursive_file_extractor.cpp
	$(BIN_FOLDER)
	$(CC) recursive_file_extractor.cpp $(HELPERS_FOLDER) $(CFLAGS) -o bin/recursive_file_extractor

clean veryclean:
	$(RM) bin/