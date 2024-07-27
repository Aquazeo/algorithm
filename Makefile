vpath %.h include
vpath %.c src

.PHONY: all clean

all: heapsort hsort mergesort

# heapsort
heapsort: heap.o heapsort.o
	$(CC) $(CFLAGS) -o bin/heapsort heap.o heapsort.o

heap.o: heap.c core.h heap.h
	$(CC) $(CFLAGS) -c src/heap.c -I include

heapsort.o: heapsort.c arrayio.h heap.h
	$(CC) $(CFLAGS) -c src/heapsort.c -I include

# hsort
hsort: hsort.o heap.o
	$(CC) $(CFLAGS) -o bin/hsort heap.o hsort.o

hsort.o: hsort.c arrayio.h heap.h
	$(CC) $(CFLAGS) -c src/hsort.c -I include

# mergesort
mergesort: merge.o mergesort.o
	$(CC) $(CFLAGS) -o bin/mergesort merge.o mergesort.o

merge.o: merge.c merge.h
	$(CC) $(CFLAGS) -c src/merge.c -I include

mergesort.o: mergesort.c arrayio.h merge.h
	$(CC) $(CFLAGS) -c src/mergesort.c -I include

# clean
clean:
	-rm -f *.o
	-rm -f bin/*
