#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GeneralNumber.h"
using namespace std;

/** Calculator program using GeneralNumber class and its subclasses.
 * @param argc Number of words on the command line.
 * @param argv Array of pointers to these words.
 */
int main(int argc, char* argv[]) {
  
  while(start_calculator()!=1){
  }

  printf("End of program.\n");
  
}

/**Asks user to enter two numbers (arguments in string form) and an operation
 * (char) and then parses those number to GeneralNumber form and then calculates
 * the result in accordance with the operation given
 * @return 0 or 1 to indicate when users want to end calculator (loop)
 */
int start_calculator(){
  string fnum_string;/*first number will first be stored in string form because
		      * getline() is needed to enter blank space when use want to stop the loop*/
  char fnum[MAX_DIGITS_OR_CHARACTERS_ENTERED];
  char snum[MAX_DIGITS_OR_CHARACTERS_ENTERED];//MAX_DIGITS_OR_CHARACTERS_ENTERED defined in GeneralNumber.h
  char oprtr[1];//size is 1 because operator allowed is only one character long
  GeneralNumber* gn1 = NULL;
  GeneralNumber* gn2 = NULL;

  while(gn1 == 0){

    printf("\nEnter first number (blank to exit): ");
    cin.getline(fnum, sizeof(fnum));
      
    if(strcmp(fnum, "\n") == 0){
      delete(gn1);
      delete(gn2);
      return 1;
    }

   gn1 = GeneralNumber::parse(fnum);
  }

  while(gn2 == 0){
    printf("\nEnter second number: ");
    scanf("%s",snum);
    
    gn2 = GeneralNumber::parse(snum);
  }

 
  printf("\nEnter operator: ");
  scanf("%s", oprtr);
  while(strcmp(oprtr, "+") != 0 && strcmp(oprtr, "-") != 0
	&& strcmp(oprtr, "*") != 0 && strcmp(oprtr, "/") != 0){
     printf("\nInvalid Operator. Use +, -, *, or /. Enter an operator again: ");
     scanf("%s", oprtr);
  }
  
  GeneralNumber* answer = calculate (gn1, gn2, oprtr);
  
  char* gs1 = gn1->toString();
  char* gs2 = gn2->toString();
  char* gs3 = answer->toString();
  printf("\n%s %s %s = %s\n", gs1, oprtr, gs2, gs3);

  free(gs1);
  free(gs2);
  free(gs3);

  delete(gn1);
  delete(gn2);
  delete(answer);

  return 0;//indicates user wants to run loop or main program again
}

/** Consumes two GeneralNumbers and an operation (string form) and then
 * and then uses helper functions to apply operations on the given objects
 * and then9 return the answer in GeneralNumber object form
 * @param fnum Number the second number will be applied on by the operation
 * @param snum Number that will be applied on the first number by the operation
 * @param oprtr Operator to be applied in string form
 * @return Answer of the operation on the two numbers in GeneralNumber form
 */
GeneralNumber* calculate(GeneralNumber* fnum, GeneralNumber* snum, char* oprtr){
  GeneralNumber* answer;

  if(strcmp(oprtr, "+") == 0){
    answer = fnum->add(snum);
  }

  if(strcmp(oprtr, "-") == 0){
    answer = fnum->subtract(snum);
  }

  if(strcmp(oprtr, "*") == 0){
    answer = fnum->multiply(snum);
  }

  if(strcmp(oprtr, "/") == 0){
    answer = fnum->divide(snum);
  }
  
  return answer;
}
