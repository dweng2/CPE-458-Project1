# Makefile
# CPE458 Project 1 : Sequential Matrix Multiplier
# Brian Danque, Darrin Weng

CC = gcc
CFLAGS = -Wall -g -pedantic -O3 
ALL = mm


all:	$(ALL)

mm:	mm.o
	$(CC) $(LDFLAGS) -o $@ $^

mm.o:	mm.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf core* *.o *.gch $(ALL)
