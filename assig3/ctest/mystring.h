/** mystring.h
 * @author Adonay Resom (started by Mike Ciaraldi)
 * Prototypes of my own version of some of the C-style string functions
*/

char* mystrdup(const char* src);
size_t mystrlen(const char *string);
char *mystrcpy(char *dest, const char *src);
char *mystrcat(char *dest, const char *src);
char *mystrncat(char* dest, const char* src, size_t n);
char *mystrncpy(char *dest, const char *src, size_t n);
char* mystrndup(const char* src, size_t n);
char random_character();
char *random_string(int length);
int random_integer(int max);

