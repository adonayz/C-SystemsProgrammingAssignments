#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include "GeneralNumber.h"

// Static methods:

/** Parses a string representing a GeneralNumber
 * @param s The string to parse
 * @return Pointer to a newly-allocated object of the correct subclass,
 *         or null pointer if unable to parse.
 */
GeneralNumber* GeneralNumber::parse(const char* s) {

  GeneralNumber* newobj = NULL;
  long n1, n2; // Numbers parsed from the command line
  int nconv; // Number of successful conversions
  
  // Try to match the input format, then create the right type object.

  // First look for GeneralRational format
  nconv = sscanf(s, " [ %ld / %ld ]", &n1, &n2); 
  if (nconv == 2) { // Recognized!
    newobj = new GeneralRational(n1, n2);
    return newobj;
  }

  // Look for GeneralDouble format
  int before_point; //Number before decimal point
  int after_point; //Number after decimal point
  double ap_dbl_convert; //after_point converted to double
  
  nconv = sscanf(s, "%d.%d", &before_point, &after_point);
  
  if(nconv == 2 && after_point>=0){
    ap_dbl_convert = after_point;
    
    while(ap_dbl_convert>1){//divides number after decimal point till its value returns to its original value
     ap_dbl_convert/=10;
    }
    
    newobj = new GeneralDouble(before_point + ap_dbl_convert);
    return newobj;
  }

  // Next look for GeneralLong format
  nconv = sscanf(s, "%ld", &n1); 
  if (nconv == 1) { // Recognized!
    newobj = new GeneralLong(n1);
    return newobj;
  }
  
  return NULL; // Nothing recognized
}

