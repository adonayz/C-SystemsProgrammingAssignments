/** file at2.c
 * @author Adonay Resom (started by Mike Ciaraldi originally)
 *
 * Program to demonstrate fixed-size arrays in C.
 */

#include <stdio.h>
#include "print_arrays.h"
#include "sort_ascending.h"

#define SIMPLE_INT_ARRAY_SIZE (10) // Used to store maximum  number of arguments allowed through command line

/** Main program consumes arguments from command line, converts them to integer, * then prints, sorts, and then again prints them.
 * @return Indicates success
 */

int main (int argc, const char* argv[]){
  int input_array[SIMPLE_INT_ARRAY_SIZE]; // Arguments entered are stored in integer form in this array
  int arguments_saved; // Final  amount of arguments that the program has processed.

  arguments_saved = saveArray(argc, argv, &input_array, SIMPLE_INT_ARRAY_SIZE);  // STEP1: Save number of elements processed because print function needs size of array

  if (arguments_saved == NULL){
    return 1;// indicated failure
  }
 
  printf("The following are numbers you entered in the order which you entered them\n");
  
  print_int_array(input_array, arguments_saved); // STEP2: Print numbers in the order in which they were originally entered

  printf("The following are those numbers you entered sorted in ascending order\n");
  
  sort_ascending(&input_array, arguments_saved); //  STEP3: Sort elements in the array in ascending order

  print_int_array(input_array, arguments_saved); // STEP4: Print numbers in ascending order

  return 0; // Success!
}
