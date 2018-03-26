CC=gcc
CFLAGS=-g -O3 -fPIC -fno-builtin

all: check

default: check

clean:
	rm -rf *.o ram_calc cache_calc *.dat memory_calculation

ram_calc: ram_calc.o
	$(CC) $(CFLAGS) $< -o $@

cache_calc: cache_calc.o
	$(CC) $(CFLAGS) $< -o $@

gdb_ram: ram_calc
	gdb ./ram_calc

gdb_cache: cache_calc
	gdb ./cache_calc

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

check-cache: clean cache_calc
	./cache_calc

check-ram: clean ram_calc
	./ram_calc

check: clean ram_calc cache_calc
	./ram_calc && ./cache_calc

  
dist:
	dir=`basename $$PWD`; cd ..; tar cvf $$dir.tar ./$$dir; gzip $$dir.tar 
