#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define MIN_SIZE 256
#define LOOP 16
#define STRIDE 8

int RANDOM = 16777216; //Big number in power of 2

int time_taken(int arr_size, int stride);

int main() {

  int recv_time = 0;
  FILE *fd = fopen("calculation.dat","w");
  
  int i;
  for (i = 0; i < 16 ; i++) { //Assuming max cache size is not greater than 64 MB (2^16 = 64MB)
    int size_of_array = MIN_SIZE * (1 << i);
    recv_time = time_taken(size_of_array, STRIDE);
    fprintf(fd, "%d:%d \n", i, recv_time);
  }
  
  return 0;
}

int time_taken(int arr_size, int stride) {
  int j, current = 0, best = 0;

  // Loop for making strides from 0 to 16
  for (j = 0; j < LOOP; j++) {
    
    int nbits = arr_size - 1;
    int x;	
    
    // Access each array element
    int *array = (int *)malloc(sizeof(int) * arr_size);
    clock_t start, diff;  

    for (x = 0; x < arr_size; x++) {
      array[x] = 1;
    }
    start = clock();

    int y;
    
    for (y = 0; y < RANDOM; y++) {
      ++array[(y * stride) & nbits];
    }
    diff = clock() - start;
    free(array);
    
    current = diff;
    if (best == 0 || current < best) {
      best = current;
    }
  }
  return best;
}
