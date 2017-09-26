/** mystring.c
 * @author Adonay Resom (started by Mike Ciaraldi)
 * My own versions of some of the C-style string functions
*/
#include <string.h>
#include <stdlib.h>
#include <time.h>
// stdlib.h is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 * @param src Pointer to string to be copied
 * @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  // Note: strcpy() always puts the null terminator at the tend of the string.
  mystrcpy(newstr, src);
  return newstr;
}


/** Duplicates a C-style string.
 * @param src Pointer to string to be copied
 * @param n Maximum charchters wanted to allocate
 * @return Pointer to freshly-allocated string containing a n characters from src string
 * or null if no memory is available
*/
char* mystrndup(const char* src, size_t n) {
  int size; // Number of bytes user wants to copy to the memory
  char* newstr; // Pointer to memory which will hold new string

  size = n + 1;  /* Maximum size n set by the user and plus one 
		  * for the terminator*/
  newstr = (char*) malloc(size); // Must cast!

  // If no memory was available, return immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  // Note: strcpy() always puts the null terminator at the tend of the string.
  mystrncpy(newstr, src, 5);
  return newstr;
}


/** Consumes a string and calculates the length of it(number of characters in a string).
 * It uses a loop that keeps on checking if the character on
 * the index i (loop counter) of the string is not the terminating byte '\0',
 * and keeps on adding 1 to a length variable till it is.
 * @param string String which its length will be calculate 
 * @return number of charachters (length) of the string in form of size_t (used for
 * counting because cant be negative)
*/
size_t mystrlen(const char *s){
  size_t len = 0;// loop counter and string length variable

  while(s[len]!='\0'){/*increase the value of len by 1 till you get
		       *to the terminating byte at the end of the string*/ 
    len++;
  }
  
  return len;
  
}


/** Consumes two strings and copies all of the charachters (including the terminating byte
 * '/0') from the source string to the destination string.
 * @param src  The source string that will be copied to the destination
 * @param dest String to which the charachters of the source string will
 * be copied
 * @return The destination string which has all charachters copied from the source string
*/
char *mystrcpy(char *dest, const char *src){
  size_t i;//for loop counter

  for(i = 0; src[i]!='\0';i++){/*increase the value of len by 1 till it gets to the
				* terminating byte at the end of the
				* string(this means it does not add the terminating
				* byte to the copy)*/
    dest[i]=src[i];/*copy the charachter from src's index position i to
		    *the same index i position in dest*/
  }
  dest[i]='\0';//adds a terminating byte to the copy

  return dest;
  
}


/** Consumes two strings and copies n number of charachters to the destination
 * (starting from the beginning) from the source string to the destination string.
 * @param src  The source string that will be copied to the destination
 * @param dest String to which the charachters of the source string will be copied
 * @param n Maximum number of charachters allowed to copy from source string
 * @return The destination string which has n number of charachters copied from the
 * source string
*/
char *mystrncpy(char *dest, const char *src, size_t n){
  size_t i;//for loop counter

  for(i = 0; src[i]!='\0' && i < n;i++){/* increase the value of len by 1 till it gets
					 * to the  terminating byte at the end of the
					 * string or till it i is equal the n number of
					 * charachters ordered to copy*/
    dest[i]=src[i];/*copy the charachter from src's index position i to
		    *the same index i position in dest*/
  }

  while(i<n){//adds a terminating byte after all charachters of destination string
    dest[i] = '\0';
    i++;
  }

  return dest;
  
}


/** Concatenates two strings (source and destination strings)by adding the source string
 * to the destination string by finding the position of the terminating byte of the
 * destination string and adding the source string starting from that position.
 * @param src  The source string from which all the charachters will be added
 * @param dest String to which the charachters of the source string will be copied
 * @return Destination string which has all the charachters of the source string added to it
*/
char *mystrcat(char *dest, const char *src){
  size_t i  = 0;// loop counter to be able to stop loop when reaching the end of src
  size_t l = mystrlen(dest); /**find the length of the destination to be able to
			      * find the position of the terminating byte**/
  
  while(src[i]!='\0'){/*increase the value of len by 1 till you get
		       *to the terminating byte at the end of the string*/
    dest[l+i]=src[i];//add charachters from source to end of the destination string
    i++;
  }
  dest[l+i]='\0';//adds a terminating byte to the final result
  
  return dest;
  
}

/** Concatenates two strings (source and destination)but only adds n bytes of the source
 * string to the destination. It finds the position of the terminating byte of the
 * destination string and adds n bytes of the source string starting from that position.
 * @param src  The source string from which all the charachters will be added
 * @param dest String to which the charachters of the source string will be copied
 * @param n maximum number of charachter to add from source string
 * @return Destination string which has all the charachters of the source string added to it
*/
char *mystrncat(char* dest, const char* src, size_t n){  
  size_t i  = 0;// loop counter to be able to stop loop when reaching the end of src
  size_t l = mystrlen(dest); /**find the length of the destination to be able to
			      * find the position of the terminating byte**/

  while(src[i] != '\0' && i<n){/*increase the value of len by 1 till you get 
				*to the terminating byte at the end of the string or n
				*number of bytes*/
    dest[l+i] = src[i];
    i++;
  }

  
  dest[l+i] = '\0';//adds a terminating byte to the final result

  return dest;
  
}


/**Generates and returns a random capital letter/character by first generating
 * a random number and using it as an index to randomly select a character from
 * an array of characters containing all the capital letters
 * @return A single character. That is a randomly selected capital letter
 */
char random_character(){
  char characters[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int c_size = mystrlen(characters);
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
