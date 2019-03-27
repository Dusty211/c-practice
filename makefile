CC=gcc
CFLAGS=-I

practicemake: practice.c
		$(CC) -o bin/practice practice.c
