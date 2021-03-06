#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GeneralNumber.h"

/** Default constructor for GeneralNumber
 */
GeneralNumber::GeneralNumber() {
  // Just a placeholder for now -- nothing to do.
}

/** Generates a printable representation of the object.
 * @return Freshly-allocated C-stype string
 */
char* GeneralNumber::toString() const {
  char* rep; // String representation of the vlaue.
  rep = strdup("Never instantiate a plain GeneralNumber!");
  return rep;
}

/** Demonstrates a non-virtual function.
 * @return Freshly-allocated C-stype string
 */
char* GeneralNumber::foo() const {
  char* rep = strdup("This is the output of foo() for GeneralNumber!");
  return rep;
}

/** Generates an equivalent GeneralLong
 * @return Pointer to a freshly-allocated GeneralLong object
 */
GeneralLong* GeneralNumber::toGeneralLong() const {
  GeneralLong* g = new GeneralLong();
  return g;
}

/** Generates an equivalent GeneralRational
 * @return Pointer to a freshly-allocated GeneralRational object
 */
GeneralRational* GeneralNumber::toGeneralRational() const {
  GeneralRational* g = new GeneralRational();
  return g;
}

/** Returns pointer to GeneralNumber
 * @return Pointer to the GeneralNumber passed in
 */
GeneralNumber* GeneralNumber::add(GeneralNumber* g) const {
  return g;
}






/** Default constructor for GeneralLong 
*/
GeneralLong::GeneralLong() {
  value = 0L; // Default value is a long zero
}

/** Constructor for GeneralLong
 * @param value Number to store in the object
 */
GeneralLong::GeneralLong(long value) {
  this->value = value;
  // "this->value" means the field inside the object.
  // Just "value" means the parameter.
}

// See header comment in GeneralNumber 
char* GeneralLong::toString() const {
  // Allocate enough space for largest possible number.
  char* rep = (char*) malloc(MAX_DIGITS_IN_LONG + 1);

  sprintf(rep, "%ld", value); // convert to printable form.
  return rep;
}

/** Demonstrates a non-virtual function.
 * @return Freshly-allocated C-stype string
 */
char* GeneralLong::foo() const {
  char* rep = strdup("This is the output of foo() for GeneralLong!");
  return rep;
}

/** Generates an equivalent GeneralLong
 * @return Pointer to a freshly-allocated GeneralLong object
 */
GeneralLong* GeneralLong::toGeneralLong() const {
  GeneralLong* g = new GeneralLong(value); // Very simple!
  return g;
}

/** Generates an equivalent GeneralRational
 * @return Pointer to a freshly-allocated GeneralRational object
 */
GeneralRational* GeneralLong::toGeneralRational() const {
  GeneralRational* g = new GeneralRational(value, 1L);
  // Slightly more complicated!
  return g;
}


/** Converts any GeneralNumber to GeneralLong and
 * then adds the value of the object it is invoked
 * on to the value found in the object it converted
 * Then returns generates a GeneralLong of the sum
 * @param gn GeneralNumber we want added to the GeneralLong
 * @return Pointer to the sum in GeneralLong form
 */
GeneralNumber* GeneralLong::add(GeneralNumber* gn) const {
  GeneralLong* converted = gn->toGeneralLong();
  
  long sum = this->value + converted->value;

  GeneralLong* g = new GeneralLong(sum);

  return g;
  
}




/** Default constructor for GeneralRational 
*/
GeneralRational::GeneralRational() {
  top = 0L;
  bottom = 1L;// Default value is a long zero over a long one
}

/** Constructor for GeneralRational
 * @param top Numerator to store in the object
 * @param bottom Denominator to store in the object
 */
GeneralRational::GeneralRational(long top, long bottom) {
  this->top = top;
  this->bottom = bottom;
  // "this->something" means the field inside the object.
  // Just "something" means the parameter.
}

// See header comment in GeneralNumber 
char* GeneralRational::toString() const {
  // Allocate enough space for largest possible number.
  char* rep = (char*) malloc((2 * MAX_DIGITS_IN_LONG) + 6);

  sprintf(rep, "[%ld / %ld]", top, bottom); // convert to printable form.
  return rep;
}

/** Demonstrates a non-virtual function.
 * @return Freshly-allocated C-stype string
 */
char* GeneralRational::foo() const {
  char* rep = strdup("This is the output of foo() for GeneralRational!");
  return rep;
}

/** Generates an equivalent GeneralLong
 * @return Pointer to a freshly-allocated GeneralLong object
 */
GeneralLong* GeneralRational::toGeneralLong() const {
  GeneralLong* g = new GeneralLong(top / bottom);
  return g;
}

/** Generates an equivalent GeneralRational
 * @return Pointer to a freshly-allocated GeneralRational object
 */
GeneralRational* GeneralRational::toGeneralRational() const {
  GeneralRational* g = new GeneralRational(top, bottom);
  return g;
}

/**Finds the GCD of the nominator and denominator
 * and divides them with their GCD to fing their
 * lowest term. Also arranges position of negative sign
 * @return Same GeneralRational but in lowest term/canonical form
 */
void GeneralRational::toCanonicalForm(){
  long gcd = find_gcd(this->top, this->bottom);

  this->top /= gcd;
  this->bottom /= gcd;

  if(this->bottom < 0){
    this->bottom *= -1;
    this->top *= -1;
  }
  
}


/**Converts GeneralNumber passed in to GeneralRational and adds
 * its value with the converted GeneralRation by the help of lcm()
 * helper function.
 * @param gn GeneralNumber we wanted added to the GeneralRational
 * @return Pointer to the sum in GeneralRational form
 */
GeneralNumber* GeneralRational::add(GeneralNumber* gn) const {
  GeneralRational* converted = gn->toGeneralRational();
  long sum;
  long lcd;
  long new_this_top;
  long new_converted_top;

  if(this->bottom != converted->bottom){
    lcd = find_lcd(this->bottom, converted->bottom);
    new_this_top = this->top * (lcd / this->bottom);
    new_converted_top = converted->top * (lcd/ converted->bottom); 
  }else{
    lcd = this->bottom;
    new_this_top = this->top;
    new_converted_top = converted->top;
  }

  sum = new_this_top + new_converted_top;

  GeneralRational* g = new GeneralRational(sum, lcd);

  g->toCanonicalForm();
  
  return g;
}

/** Finds the Greatest Common Divisor of two numbers
 * @param a One of two numbers we want the GCD of
 * @param b One of two numbers we want the GCD of
 * @return The GCD of the two numbers in long format
 */
long find_gcd(long a, long b){
  long s;

  while(a!=0){
    s = a; a = b%a; b = s;
  }
  return b;
}

/**Finds the Least Common Denominator of two numbers
 * @param a One of two numbers we want LCD of
 * @param b One of two numbers we want LCD of
 * @return The GCD of the two numbers in long format
 */
long find_lcd(long a, long b){
  long s;

  s = a*b/find_gcd(a,b);

  return s;
}
