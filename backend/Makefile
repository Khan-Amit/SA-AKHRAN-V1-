CC = gcc
CFLAGS = -Wall -O2

all: sluice1 sluice2 sluice3

sluice1: sluice-bench-1.c
	$(CC) $(CFLAGS) -o sluice1 sluice-bench-1.c

sluice2: sluice-bench-2.c
	$(CC) $(CFLAGS) -o sluice2 sluice-bench-2.c

sluice3: sluice-bench-3.c
	$(CC) $(CFLAGS) -o sluice3 sluice-bench-3.c

clean:
	rm -f sluice1 sluice2 sluice3
