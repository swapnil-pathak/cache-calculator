# cache-calculator

Building and running:
1. Run 'make clean' to remove any precompiled packages
2. Run 'make check-cache' to compile and run the program cache_calc.c 
3. You can run a python script to get graphical output by typing 'python plot.py'

Alternatively,
Run 'make cache_calc' to build executable and then run './cache_calc' to run it. 
Then, run 'python plot.py' to get graphical output.

NOTE: For graphical output, python packages matplotlib and Tkinter need to be installed.
They can be installed using the following commands.
1. pip install matplotlib
2. apt-get install python-tk

If the above packages are not present, graphical output cannot be seen.

In case, graphical output is not needed, a file named 'calculation.dat' is generated which contains rows of plot points which are in format of "power of 2:Time"


##################################################################################################################

NOTE: Running a simple 'make' will generate the executables and produce the output in the files mentioned before.

##################################################################################################################

###########################################
METHODOLOGY FOR CACHE CALCULATION
###########################################
Assuming that the max cache size is 2 ^ 16 MB, a loop is set for making strides from 0 to 16.

Each iteration consists of 16777216 (2 ^ 24) number of operations.

Each iteration of such an operation tries to read an integer from a slot in the array, increase it, and write it back.

The entire operation is calculated in processor time.

When the size of array ( N * Cache_size)) exceeds the next level cache size, the read and write performance will drop. A steep increase of Time should be observed in the generated graph.

############################################
DESCRIPTIONS OF GRAPHS
############################################

***Figure_1.png***

The X axis is the power of 2, on a system where integer size is 4 bytes. The Y axis is the access time in microseconds.

The first steep increase happens when X is 5. The size of array is 2 ^ 5 * 1kB = 32kB.

The second steep increase happens when X is 8. The array size is 256kB.

The third steep increase happens when X is 11. The array size is 2MB.

Thus, the 3 levels of caches are 32kB, 256kB, and 2MB.

***Figure_2.png***

The first steep increase happens when X is 4. The size of array is 16kB.

The second steep increase happens when X is 7. The array size is 128kB.

The third steep increase happens when X is 11. The array size is 2MB.

Thus, the 3 levels of caches are 16kB, 128kB, and 2MB.
