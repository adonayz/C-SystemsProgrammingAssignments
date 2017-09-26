/** file print_arrays.c
 * @author Adonay Resom (Started by Mike Ciaraldi)
 *
 * Functions for printing arrays.
 */

#include <stdio.h>
#include "print_arrays.h"

/** Print an array of ints, one per line.
    @param a Array of integers to print
    @param num_entries Number of entries in the array
*/

void print_int_array(int a[], int num_entries) {
  int i; // Loop counter

  for (i =0; i < num_entries; i++) {
    printf("%d\n", a[i]);
  }
}


/** Print an array of doubles, one per line.
    @param a Array of doubles to print
    @param num_entries Number of entries in the array
*/
void print_double_array(double a[], int num_entries) {
  int i; // Loop counter

  for (i =0; i < num_entries; i++) {
    printf("%f\n", a[i]);
  }
}


/** Collects arguments from command line, converts them to integer, saves them into an array located in the main function through a pointer
    @param argc Number of arguments entered plus the prompt itself
    @param argv An array that contains the arguments entered through the command line (in order of entry)
    @param input_array A pointer to an integer array in which the arguments entered will be stored in
    @param array_size Number of elements allowed to be saved into the input_array
    @return NULL indicates error. All other values indicate success!
*/
int saveArray(int argc, const char* argv[], int* input_array, int array_size){
  int i;// for loop counter

  if (argc < 2){ // Check that there was an entry
    printf("Must enter a number on the command line!\n");
    return NULL; // Indicate failure
  }

  int no_of_arguments = argc -1; //Calculates number of arguments entered through command line

  /** loop that adds command line arguments into an array after converting 
   * them into an integer. Loop stops if maximum array size has been reached or all arguments are processed*/
  for(i = 0; i < array_size && i < no_of_arguments; i++){
    
    input_array[i]=atoi(argv[i + 1]);/*takes an argument, converts it to an integer,
				       * and then stores it the corresponding position
				       * of the array.*/

  }

  if(no_of_arguments>array_size){// produces message if the number of arguments entered is more than the allowed array size

    printf("You have entered more than the allowed number of argumennts. Only %d numbers have been stored\n", array_size);

    return NULL;// Indicates error!
  }

  return i; // Indicates Success (Any other number than 1 indicates success)
  
}
