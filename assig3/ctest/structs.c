/**structs.c
 * @author Adonay Resom
 * Functions that process the struct Employee I created
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// string.h covers the C-style string functions.
#include "mystring.h"
#include "structs.h"

#define MAX_NAME 10

/**Creates and allocates an Employee struct and fill its fields with the
 * paramaters passed into it
 * @param name Name of the employee
 * @param birth_year The year of birth of the employee
 * @param start_year Year at which the employee got employed
 * @return Pointer to newly created and  allocated Employee struct
*/
struct Employee* make_employee(char* name, int birth_year, int start_year){
  
  struct Employee *e = (struct Employee*) malloc(sizeof(struct Employee));
  
  mystrcpy(e->name, name);
  e->birth_year = birth_year;
  e->starting_year = start_year;

  return e;
  
}


/**Consumes a pointer to an Employee struct and prints the values of the fields
 * of that struct. In other words, prints Employee struct
 * @param e Pointer to the Employee struct the user wants to be printed
*/
void print_employee(struct Employee* e){
  printf("\nEmployee Name: %s\n", e->name);
  printf("Employee Birth Year: %d\n", e->birth_year);
  printf("Employee Starting Year: %d\n", e->starting_year);
}



/**Generates randomly generated employee
 * @return A new Employee struct contaning randomly generated field values.
 * 
*/
struct Employee* random_employee(){
  char* name = random_string(MAX_NAME);
  int birth_year = random_integer(2016);
  int start_year = random_integer(2016);
  struct Employee* e;

  e = make_employee(name, birth_year, start_year);

  free(name);

  return e;
  
}

/**Generates an array of count(int) pointers pointing to randomly generated employees
 * @param count integer representing amount of random employees generated
 * @return A new array containing pointer pointing to randomly generated employees.
 * 
*/
struct Employee** random_employee_array(int count){
  int i; // loop counter
  struct Employee **employee_array;

  employee_array = (struct Employee**) malloc(count * sizeof(struct Employee*));

  for(i = 0; i< count; i++){
    employee_array[i] = (struct Employee*) malloc(sizeof(struct Employee));
    employee_array[i] = random_employee();
  }

  return employee_array;
}

/**Consumes a pointer to an array containing pointers to Employee structs and
 * the array size, and uses those pointers to print each employee using the
 * print_employee function created to print Employee struct fields.
 * @param employee_array Array contaning pointers to the struct getting printed
 * @param count size of array
*/
void print_employee_array(struct Employee** employee_array, int count){
  int i; // loop counter
  for(i = 0; i < count; i++){
    print_employee(employee_array[i]);
  }
  
}

/**Consumes a pointer to an array containing pointers to Employee structs and
 * the array size, and copies those pointers into another array that it creates
 * and allocates. The new array also holds pointers to Employee structs. In short
 * it performs a shallow copy.
 * @param employee_array Array contaning pointers getting copied
 * @param count size of array
 * @return A new array containing the same pointers pointing to the same Employee struct
 * 
*/
struct Employee** duplicate_employee_array_shallow(struct Employee** employee_array, int count){
  int i; // loop counter
  struct Employee **duplicate_array;

  duplicate_array = (struct Employee**) malloc(count * sizeof(struct Employee*));
  
  for(i = 0; i< count; i++){
    duplicate_array[i] = employee_array[i];
  }

  return duplicate_array;
}

/**Frees/Deallocates all the structs the pointer in the array are pointing to.
 * @param employee_array Array contaning pointers getting deallocated
 * @param count size of array
 */
void free_employee_array(struct Employee** employee_array, int count){
  int i; // loop counter
  
  for(i = 0; i< count; i++){
    free(employee_array[i]);
  }

  free(employee_array); 
}


//EXTRA CREDIT FUNCTION
/**Consumes a pointer to an array containing pointers to Employee structs and
 * the array size, and copies all data from the struct the pointers are pointing
 * to, into a new Employee struct. And then it creates a new pointer pointing to
 * the new Employee struct and stores the pointers into a new array. In short
 * it performs a deep copy.
 * @param employee_array Array contaning pointers to the struct getting copied
 * @param count size of array
 * @return A new array containing new pointers pointing to a new Employee struct
 * the same data as the old one.
 * 
*/
struct Employee** duplicate_employee_array_deep(struct Employee** employee_array, int count){
  int i; // loop counter
  struct Employee **duplicate_array;

  duplicate_array = (struct Employee**) malloc(count * sizeof(struct Employee*));
  
  for(i = 0; i< count; i++){
    struct Employee* current_e = employee_array[i];
    struct Employee* e = make_employee(current_e->name, current_e->birth_year, current_e->starting_year);
    
    duplicate_array[i] = (struct Employee*) malloc(sizeof(struct Employee));    
    duplicate_array[i] = e;
  }

  return duplicate_array;
}
