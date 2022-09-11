CC      = gcc
CFLAGS  = -g -Werror
RM      = rm -f


default: all

all: num_to_text

num_to_text: num_to_text.c
	$(CC) num_to_text.c $(CFLAGS) -o bin/num_to_text

clean veryclean:
	$(RM) num_to_text