/** mystring.h
 * @author Adonay Resom
 * Prototypes of my own version of C-style string functions
*/


#define MAX_CHARS 100

struct Employee{
    char name[MAX_CHARS];
    int birth_year;
    int starting_year;
  };

struct Employee* make_employee(char* name, int birth_year, int start_year);
void print_employee(struct Employee* e);
struct Employee* random_employee();
struct Employee** random_employee_array(int count);
void print_employee_array(struct Employee** employee_array, int count);
struct Employee** duplicate_employee_array_shallow(struct Employee** employee_array, int count);
void free_employee_array(struct Employee** employee_array, int count);
struct Employee** duplicate_employee_array_deep(struct Employee** employee_array, int count);
