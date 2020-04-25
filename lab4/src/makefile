CC=gcc
CFLAGS=-I.

all : process_memory

process_memory :
	$(CC) -o process_memory process_memory.c $(CFLAGS)

parallel_sum : utils.o
	$(CC) -o parallel_sum ../../lab3/src/utils.o parallel_sum.c $(CFLAGS) -lpthrea
utils.o : ../../lab3/src/utils.h
	$(CC) -o ../../lab3/src/utils.o -c ../../lab3/src/utils.c $(CFLAGS)

clean :
	rm process_memory.o process_memory
