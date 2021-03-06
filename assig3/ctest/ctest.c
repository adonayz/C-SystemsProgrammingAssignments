#include <stdio.h>
#include <string.h>
// string.h covers the C-style string functions.
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Adonay Resom (started by Mike Ciaraldi)
 */

const int MAX_CHARS = 20; // Maximum number of characters in array


/** Main program demostrates how self created version of string functions work
 * @return 0 Indicates success. 1 indicates failure.
 */
int main()
{
  char a1[MAX_CHARS + 1]; // Character array--initially empty
  char a2[] = "Hello"; // Character array--unsized but initialized
  char a3[MAX_CHARS + 1]; // Character array--we will underfill it
  char* p1 = "Hello"; // Pointer to constant string
  char* p2;           // Will be a pointer to dynamically-allocated string
  int copy_limit;     // Maximum characters to copy.

  strcpy(a3, "Hello, also"); // Initialize underfilled character array

  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
  printf("          p1 = %p p2 = %p\n", p1, p2);

  strcpy(a1, "Hi"); // Initialize character array

  printf("Contents of a1 = %s\n", a1);
  printf("Contents of a2 = %s\n", a2);
  printf("Contents of a3 = %s\n", a3);

  // Concatenate two character arrays, then print.
  mystrcat(a1, a2);
  printf("After concatenating a2 to a1, contents of a1 = %s\n", a1);

  // Concatenate two character arrays with limit, then print.
  mystrncat(a1, a2, 8);
  printf("After concatenating a2 to a1, max length 8, contents of a1 = %s\n",
         a1);

  // Copy with limit.
  strncpy(a1, a2, 3);
  printf("After copying a2 to a1, max length 3, contents of a1 = %s\n", a1);
  printf("Note that copied string was not terminated.\n");

  // Reset a1
  strcpy(a1, "Hi"); // Initialize character array
  printf("Resetting. a1 = %s\n", a1);

  // Concatenate two character arrays with limit, then print.
  mystrncat(a1, a2, 2);
  printf("After concatenating a2 to a1, max length 2, contents of a1 = %s\n",
         a1);
  printf("Note that copied string was terminated.\n");


  // Duplicate a string, using my function, then print
  printf("Before dup, pointer a2 = %p, contents = %s\n", a2, a2);
  p2 = mystrdup(a2);
  printf("After dup, pointer p2 = %p, contents = %s\n", p2, p2);

  printf("\n\nDemostrating mystrncpy and mystrndup for section B part 2:\n");

  printf("\nNow testing mystrncpy:\n");
  
  char str1[] = "12345678910";
  char str2[] = "abcdefghij";

  printf("\nstr1: %s\nstr2: %s\n",str1, str2);

  mystrncpy(str1, str2, 5);

  printf("\n(str1, str2, 5);\n");

  printf("\nAfter copying str2 to str1, max length 5, content of str1 is = %s\n", str1);

  printf("\nNow testing mystrndup:\n");

  char *tp;// pointer for dynamically allocated string from mystrndup

  printf("\nResetting str1:\n");

  strcpy(str1, "12345678910");

  printf("\nstr1: %s\n",str1);

  printf("\nBefore dup, pointer str1 = %p, contents = %s\n", str1, str1);
  tp = mystrndup(str1, 5);
  printf("\ntp = mystrdup(str1, 5);\n");
  printf("\nAfter dup with max size of 5, pointer tp = %p, contents = %s\n", tp, tp);
  

  
  
  return 0;
}
