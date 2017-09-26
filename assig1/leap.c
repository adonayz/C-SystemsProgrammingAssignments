#include <stdio.h>
#include <stdlib.h>

/* This is a simple program that enables it's user to test if a year can be 
 * catagorized  as a leap year. The program is designed to handle year 1752 and  * later only.
 *
 * Usage:
 *         ./num year_input
 * Example:
 *         ./num 1998
 *
 */

int main (int argc, const char* argv[]){
  int n; // Integer read from the command line goes here.

  if (argc < 2){ // Check that there was an entry
    printf("Must enter a number on the command line!\n");
    return 1; // Indicate failure
  }

  n = atoi(argv[1]); // Get string from command line; convert to int

  if(n < 1752){// Checks if the input year/integer is before the year 1972 (year US adapted the G.C.)

    printf("%d is not a valid year input. The program is not designed to test years before 1752(G.C)\n", n);
    return 1;// Return value is 1 to indicate input value error
    
  }else{
    
    if(n%4 == 0){// Checks if year is evenly divsible by 4
      if(n%100 == 0){// Checks if year is evenly divisble by 100
	if(n%400 == 0){// Checks if year is evenly divisble 400
	  
	  printf("%d is a leap year.\n",n);
	  return 0; // Indicates program success
	  
	}
	
	printf("%d is not  a leap year.\n",n);
	return 0; // Indicates program success
      }

      printf("%d is a leap year.\n",n);
      return 0; // Indicates program success
      
    }else{

      printf("%d is not  a leap year.\n",n);
      return 0; // Indicates program success

    }
    
  }
}
