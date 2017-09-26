#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Tree.h"

/** Program to demonstrate the Tree and Tnode class with random charachters.
 * @param argc Number of words on the command line.
 * @param argv Array of pointers to these words.
 */
int main(int argc, char* argv[]) {
  int i;//loop counter

  srand(time(NULL));

  Tree* newTree = new Tree();

  for(i = 0; i<10; i++){
    newTree->add(random_string(MAX_CHARS)); //MAX_CHARS defined in Tree.h
  }

  newTree->printAscending();

  printf("\n");

  newTree->freeTree();
  
  delete(newTree);
  
  return 0; //indicates success
  
}


/**Generates and returns a random capital letter/character by first generating
 * a random number and using it as an index to randomly select a character from
 * an array of characters containing all the capital letters
 * @return A single character. That is a randomly selected capital letter
 */
char random_character(){
  char characters[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int c_size = strlen(characters);
  int random_number;
  char random_character;

  random_number = rand() % c_size; /*to limit the maximum of value of the
				    * random number created*/
  random_character = characters[random_number];

  return random_character;
}



/**Creates, allocates and returns a pointer to a random string it has created.
 * The string consists of all capital letters, and always a length that the 
 * user passes as a parameter. It uses the function random_character()
 * repeatedly to generate a string of size length.
 * @param length Size of the newly genrated string
 * @return A pointer to the newly allocated and randomly generated string.
 */
char *random_string(int length){
  int i; //loop counter
  char* new_string;
  
  new_string = (char*) malloc(length+1);

  for(i = 0; i<length; i++){
    new_string[i]= random_character();
  }

  new_string[length] = '\0';

  return new_string;
    
}


/** Return a random number from 0 to maximum specified number.
    @param max Maximum specified value for random number generator
    @return random number
*/
int random_integer(int max){
  return rand() % max;  
}
