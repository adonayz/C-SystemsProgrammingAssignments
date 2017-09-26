/**main.c
 * Program to demonstrate structs
 * @author Adonay Resom
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// string.h covers the C-style string functions.
#include "mystring.h"
#include "structs.h"

#define MAX_CHARS 100

/** Main program Demostrates use and processes on the struct Employee
 * @return 0 Indicates success. 1 Indicates failure
 */
int main()
{
  srand(time(NULL));
  
  char name1[MAX_CHARS] = "Adonay";
  char name2[MAX_CHARS] = "Peter";
  char name3[MAX_CHARS] = "Ben";
  char name4[MAX_CHARS] = "Nelson";
  
  struct Employee* e1;
  struct Employee* e2;
  struct Employee* e3;
  struct Employee* e4;
  
  e1 = make_employee(name1, 1997, 2016);
  e2 = make_employee(name2, 1994, 2010);
  e3 = make_employee(name3, 1988, 2005);
  e4 = random_employee();

  printf("\nTesting functions make_employee and print_employee\n");
    
  print_employee(e1);
  print_employee(e2);
  print_employee(e3);

  printf("\nTesting functions random_employee and print_employee\n");
  print_employee(e4);

  char* randstr = random_string(10);
  printf("\nTesting random_string function. New string is : %s\n", randstr);

  printf("\nTesting print_employee_array() function. Generates 5 random employee arrays.\n");

  print_employee_array(random_employee_array(5), 5);

  printf("\nTesting duplicate_employee_array_shallow() function\n\nPrinting array rea1");

  struct Employee** rea1 = random_employee_array(3);
  print_employee_array(rea1, 3);
  
  printf("\nPerform a shallow copy of array rea1, onto array rea2\n");

  struct Employee** rea2 = duplicate_employee_array_shallow(rea1, 3);

  printf("\nPrinting array rea2, after duplicating it from rea1");

  print_employee_array(rea2, 3);

  printf("\nCOMPARING rea1 and rea2 after duplicating (SHALLOW copy)\n");
  
  printf("\nPointer assigned to the array rea1 after shallow copy: %p\n", rea1);

  printf("\nThe pointers assigned to each employee in rea1 after shallow copy:\n");

  for(int i = 0; i < 3; i++){
    printf("%p\n", rea1[i]);
  }
  
  printf("\nPointer assigned to the array rea2 after shallow copy: %p\n", rea2);

  printf("\nThe pointers assigned to each employee in rea2 after shallow copy:\n");

  for(int i = 0; i < 3; i++){
    printf("%p\n", rea2[i]);
  }


  







 printf("\nTesting duplicate_employee_array_deep() function\n\nPrinting array rea3");

  struct Employee** rea3 = random_employee_array(3);
  print_employee_array(rea3, 3);
  
  printf("\nPerform a deep copy of array rea3, onto array rea4\n");

  struct Employee** rea4 = duplicate_employee_array_deep(rea3, 3);

  printf("\nPrinting array rea4, after duplicating it from rea3");

  print_employee_array(rea4, 3);

  printf("\nCOMPARING rea3 and rea4 after duplicating (DEEP copy)\n");
  
  printf("\nPointer assigned to the array rea3 after deep copy: %p\n", rea3);

  printf("\nThe pointers assigned to each employee in rea3 after deep copy:\n");

  for(int i = 0; i < 3; i++){
    printf("%p\n", rea3[i]);
  }
  
  printf("\nPointer assigned to the array rea4 after shallow copy: %p\n", rea4);

  printf("\nThe pointers assigned to each employee in rea4 after shallow copy:\n");

  for(int i = 0; i < 3; i++){
    printf("%p\n", rea4[i]);
  }
  

  printf("\nTHEREFORE: as you can see from above, a shallow duplicate copies the \npointers in the array, while a deep copy copies the data pointer are \nleading to into new pointers and copies those pointers in to the new array\n");












  
  printf("\nFree employee array from memory\n");

  free_employee_array(rea1, 3);
  free_employee_array(rea2, 3);
  
  free(e1);
  free(e2);
  free(e3);
  free(e4);
  free(randstr);
  
  return 0;
  
}
