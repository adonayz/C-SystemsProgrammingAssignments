/** file at3.c
 * @author Adonay Resom
 *
 * Program to demonstrate fixed-size arrays in C.
 */

#include <stdio.h>
#include "print_arrays.h"
#include "sort_ascending.h"


/** Main program to create an array of random numbers. Array has user specified size
 * @return 0, Indicating success.
 */

#define RANDOM_ARRAY_SIZE (10) // Size of randomly generated array
#define MAXIMUM (20) // Specified maximum for random number genrator

int main (int argc, const char* argv[]){
  
  int*p; // pointer for array from random_array function
  int i; // loop counter
  int recieved_array[RANDOM_ARRAY_SIZE];

  srand((unsigned) time (NULL));// I researched this from tutorialspoint.com

  
  p = random_array(RANDOM_ARRAY_SIZE, MAXIMUM);

  for(i = 0; i<RANDOM_ARRAY_SIZE; i++){
    recieved_array[i] = *(p+i);
  }

   printf("The following are randomly generated numbers that are NOT sorted\n");

  print_int_array(recieved_array, RANDOM_ARRAY_SIZE);//Print randomly generated numbers unsorted

  printf("The following are randomly generated numbers that are sorted in ascending order\n");
  
  sort_ascending(&recieved_array, RANDOM_ARRAY_SIZE); //  STEP3: Sort elements in the array in ascending order

  print_int_array(recieved_array,RANDOM_ARRAY_SIZE); // STEP4: Print numbers in ascending order

  return 0; // Success!
}

