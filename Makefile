vpath %.h include
vpath %.c src

.PHONY: all clean

all: heapsort hsort

# heapsort
heapsort: heap.o heapsort.o
	$(CC) $(CFLAGS) -o bin/heapsort heap.o heapsort.o

heap.o: heap.c heap.h
	$(CC) $(CFLAGS) -c src/heap.c -I include

heapsort.o: heapsort.c include/heap.h
	$(CC) $(CFLAGS) -c src/heapsort.c -I include

# hsort
hsort: hsort.o heap.o
	$(CC) $(CFLAGS) -o bin/hsort heap.o hsort.o

hsort.o: hsort.c
	$(CC) $(CFLAGS) -c src/hsort.c -I include

# clean
clean:
	-rm -f *.o
	-rm -f bin/*
