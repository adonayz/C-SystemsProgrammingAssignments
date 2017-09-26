/* Program to demonstrate the use of the stat() function 
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdint.h>
#include <pwd.h>

// Function prototypes
char* uint32_t_toString(mode_t mode);

int main(int argc, char* argv[]) {

  int result; // Result of calling stat()
  struct stat status; // Struct for holding status
  char* modestring; // Printable form of file mode
    
  if (argc != 2) {
    printf("Usage:  stattest filename\n");
    return 1;
  }

  printf("Program to demonstrate the stat() function.\n");
  printf("Filename = %s\n", argv[1]);

  // Call the stat() function to fill in the struct.
  result = stat(argv[1], &status); 

  printf("Return value of stat() = %d\n", result);
  if (result < 0) {
    printf("Error. errno = %d: %s\n", errno, strerror(errno));
    return 1;
  }

  // Note: This would be non-portable on machines where mode_t is not
  // unsigned 32.
  printf("Inside the stat struct:\n");
  modestring = uint32_t_toString(status.st_mode);
  printf("st_mode =   %s\n", modestring);
  free(modestring);
  // Permissions are the right-most 9 bits.
  modestring = uint32_t_toString(status.st_mode & 0x1FF);
  printf("permissions = %s\n", modestring);
  free(modestring);
  
  printf("S_ISREG(st_mode) = %d\n", S_ISREG(status.st_mode));
  printf("S_ISDIR(st_mode) = %d\n", S_ISDIR(status.st_mode));

  printf("size: %ld\n", status.st_size);

  //modestring = uint32_t_toString(status.st_uid);
  //struct passwd* pw = getpwnam(modestring);
  //free(modestring);

  struct passwd* pw = getpwuid(status.st_uid);

  modestring = pw->pw_name;
  printf("file owner name: %s\n", modestring);
  free(modestring);
  
  return 0;
}

/** Generates a printable representation of an unsigned 32-bit value.
 * For example, one of type mode_t, such as returned by stat().
 * @param mode Au unsigned 32-bit value 
 * @return A freshly-allocated character array with the value in decimal,
 *    hex, and binary. Remember to free when done using it!
 */
char* uint32_t_toString(uint32_t mode) {

#define MAX_UINT32_T_CHARS (50)
  char* rs = (char*) malloc(MAX_UINT32_T_CHARS + 1);
      // String to fill in and return
  int i; // Loop counter
  uint32_t tmode; // Temporary copy
  
  // First do the decimal and hex forms, with blank between and after.
  sprintf(rs, "%u %4.4x ", mode, mode);

  // Now generate the binary form, starting with the MSB.
  tmode = mode;
  for (i = 0; i < 32; i++) {
    // Check the highest-order bit
    if (tmode & 0x80000000) {
      strcat(rs, "1");
    } else {
      strcat(rs, "0");
    }
    tmode <<= 1; // Shift left one bit 
  }

  return rs;
}
