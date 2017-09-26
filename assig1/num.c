#include <stdio.h>
#include <stdlib.h>
#include "connect.h"

/* Very simple program to demonstrate reading a numer from the command line.
 * Usage:
 *         ./num some_number
 * Example:
 *         ./num 2014
 *
 */

#define MAX_GRADES (5) // Used to store maximum  number of arguments allowed through command line
int analyze_array(int array_in[], int size);// function prototype

int main (int argc, const char* argv[]){
  int counter; // for loop counter
  int input_array[MAX_GRADES]; // Arguments entered are stored in integer form in this array

  if (argc < 2){ // Check that there was an entry
    printf("Must enter a number on the command line!\n");
    return 1; // Indicate failure
  }

  int no_of_arguments = argc -1; //Calculates number of arguments entered through command line

  /* loop that adds command line arguments into an array after converting 
   * them into an integer. Loop stops if MAX GRADES number or all arguments are processed*/
  for(counter = 0; counter < MAX_GRADES && counter < no_of_arguments; counter++){
    
    input_array[counter]=atoi(argv[counter + 1]);/*takes an argument, converts it to an integer,
						  * and then stores it the corresponding position
						  * of the array.*/

  }

  if(no_of_arguments>MAX_GRADES){// produces message if more than MAX_GRADES have been entered

    printf("You have entered more than the allowed number of grades. Only %d grades have been registered\n", MAX_GRADES);

    return 1;// Indicates error!
  }
  
  return analyze_array(input_array, no_of_arguments);//calls analayze_array function
}
