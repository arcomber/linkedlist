CC=gcc
CFLAGS=-I.

test:  linkedlist.o test.o
	$(CC) $(CFLAGS) -o test linkedlist.o test.o

linkedlist.o:
	$(CC) $(CFLAGS) -c linkedlist.c

test.o:
	$(CC) $(CFLAGS) -c test.c


clean:
	rm -f *.o test
