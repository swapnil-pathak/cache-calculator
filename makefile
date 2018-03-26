CC=gcc
CFLAGS=-g -O3 -fPIC -fno-builtin

all: check

default: check

clean:
	rm -rf *.o cache_calc *.dat memory_calculation

cache_calc: cache_calc.o
	$(CC) $(CFLAGS) $< -o $@

gdb_cache: cache_calc
	gdb ./cache_calc

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

check-cache: clean cache_calc
	./cache_calc

check: clean cache_calc
	./cache_calc
