OBJS = reality.o reality4.o
CC = gcc
PROGS = reality reality4

.PHONY: all clean

all: $(PROGS)

reality: reality.o
	$(CC) reality.c -o reality

reality4: reality4.o
	$(CC) reality4.c -o reality4

clean:
	rm -f *.o *~ reality reality4
