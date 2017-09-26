/** file sort_ascending.c
 * @author Adonay Resom (Started by Mike Ciaraldi)
 *
 * Functions for sorting arrays in ascending order.
 */

#include <stdio.h>
#include <stdlib.h>
#include "sort_ascending.h"

/** Sorts an array's elements in ascending order
    @param array_to_sort A pointer to an integer array containing integers to get sorted
    @param array_size The maximum number of elements allowed in this array 
*/
void sort_ascending(int* array_to_sort, int array_size){
  int i;
  int j;
  int temp;
  
  for(i = 0; i < array_size; i++){

    for(j = 0; j < (array_size - i - 1); j++){

      if(array_to_sort[j] > array_to_sort[j+1]){
	temp = array_to_sort[j];
	array_to_sort[j] = array_to_sort[j+1];
	array_to_sort [j + 1] = temp;
      }
    }

  }

}

/** Return a random number from 0 to maximum specified number.
    @param max Maximum specified value for random number generator
    @return random number
*/
int random_integer(int max){
  return rand() % max;  
}

/** Generate a specified size  array filled with random numbers
    @param size Size of array created
    @param max Maximum value for each random numbers generated
    @return randomly generated array
*/
int * random_array(int size, int max){
  int i;//loop counter
  static int result_array[10];

  for(i = 0; i < size; i++){
    result_array[i]= random_integer(max+1);
  }

  return result_array;
}

