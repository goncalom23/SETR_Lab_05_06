# Makefile with variables
P=trab2_teste
OBJECTS=	main.o	cmdproc.o
CFLAGS	=	-g	-Wall	-O3
LDLIBS=
CC=gcc
# Generate application
$(P):	$(OBJECTS)
	$(CC)	$(CFLAGS)	-o	$(P)	$(OBJECTS)
#generate fifo.o
fifo.o:	cmdproc.c	cmdproc.h
	$(CC)	$(CFLAGS)	-c	cmdproc.c
#generate main.o
main.o:	main.c	cmdproc.h
	$(CC)	$(CFLAGS)	-c	main.c
clean:
	rm	*.o	$(P)