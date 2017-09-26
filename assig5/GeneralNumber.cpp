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
}

/** Generates an equivalent GeneralRational
 * @return Pointer to a freshly-allocated GeneralRational object
 */
GeneralRational* GeneralNumber::toGeneralRational() const {
}

/** Generates an equivalent GeneralDouble
 * @return Pointer to a freshly-allocated GeneralDouble object
 */
GeneralDouble* GeneralNumber::toGeneralDouble() const {
}

/** Returns pointer to GeneralNumber
 * @return Pointer to the GeneralNumber passed in
 */
GeneralNumber* GeneralNumber::add(GeneralNumber* g) const {
}

/** Returns pointer to GeneralNumber
 * @return Pointer to the GeneralNumber passed in
 */
GeneralNumber* GeneralNumber::subtract(GeneralNumber* g) const {
}

/** Returns pointer to GeneralNumber
 * @return Pointer to the GeneralNumber passed in
 */
GeneralNumber* GeneralNumber::multiply(GeneralNumber* g) const {
}

/** Returns pointer to GeneralNumber
 * @return Pointer to the GeneralNumber passed in
 */
GeneralNumber* GeneralNumber::divide(GeneralNumber* g) const {
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


/** Generates an equivalent GeneralDouble
 * @return Pointer to a freshly-allocated GeneralDouble object
 */
GeneralDouble* GeneralLong::toGeneralDouble() const {
  GeneralDouble* g = new GeneralDouble(value); // Very simple!
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

/** Converts any GeneralNumber to GeneralLong and
 * then subtracts the value of the object it is invoked
 * on to the value found in the object it converted
 * Then returns generates a GeneralNumber of the difference
 * @param gn GeneralNumber we want subtracted from the GeneralLong
 * @return Pointer to the sum in GeneralLong form
 */
GeneralNumber* GeneralLong::subtract(GeneralNumber* gn) const {
  GeneralLong* converted = gn->toGeneralLong();
  
  long difference = this->value - converted->value;

  GeneralLong* g = new GeneralLong(difference);

  return g;
  
}

/** Converts any GeneralNumber to GeneralLong and
 * then multiplies the value of the object it is invoked
 * on to the value found in the object it converted
 * Then returns generates a GeneralLong of the product
 * @param gn GeneralNumber we want multiplied to the GeneralLong
 * @return Pointer to the product in GeneralLong form
 */
GeneralNumber* GeneralLong::multiply(GeneralNumber* gn) const {
  GeneralLong* converted = gn->toGeneralLong();
  
  long product = this->value * converted->value;

  GeneralLong* g = new GeneralLong(product);

  return g;
  
}

/** Converts any GeneralNumber to GeneralLong and
 * then divides the value of the object it is invoked
 * on to the value found in the object it converted
 * Then returns generates a GeneralLong of the quotient
 * @param gn GeneralNumber we want to divide the GeneralLong with
 * @return Pointer to the quotient in GeneralLong form
 */
GeneralNumber* GeneralLong::divide(GeneralNumber* gn) const {
  GeneralLong* converted = gn->toGeneralLong();
  
  long quotient = this->value / converted->value;

  GeneralLong* g = new GeneralLong(quotient);

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


/** Generates an equivalent GeneralDouble
 * @return Pointer to a freshly-allocated GeneralDouble object
 */
GeneralDouble* GeneralRational::toGeneralDouble() const {
  GeneralDouble* g = new GeneralDouble(top / bottom); // Very simple!
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

/**Converts GeneralNumber passed in to GeneralRational and subtracts
 * its value with the converted GeneralRational by the help of lcm()
 * helper function.
 * @param gn GeneralNumber we wanted subtracted from the GeneralRational
 * @return Pointer to the sum in GeneralRational form
 */
GeneralNumber* GeneralRational::subtract(GeneralNumber* gn) const {
  GeneralRational* converted = gn->toGeneralRational();
  long difference;
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

  difference = new_this_top - new_converted_top;

  GeneralRational* g = new GeneralRational(difference, lcd);

  g->toCanonicalForm();
  
  return g;
}

/**Converts GeneralNumber passed in to GeneralRational and multiplies
 * its top and bottom values  with the converted GeneralRational's top and
 * bottom values and then return's the result in GeneralRational form.
 * @param gn GeneralNumber we wanted multiplied to the GeneralRational
 * @return Pointer to the sum in GeneralRational form
 */
GeneralNumber* GeneralRational::multiply(GeneralNumber* gn) const {
  GeneralRational* converted = gn->toGeneralRational();
  long product_top;
  long product_bottom;

  product_top = this->top * converted->top;
  product_bottom = this->bottom * converted->bottom;

  GeneralRational* g = new GeneralRational(product_top, product_bottom);

  g->toCanonicalForm();
  
  return g;
}

/**Converts GeneralNumber passed in to GeneralRational and divides
 * its value with the converted GeneralRational by inverting the top and bottom
 * values of the converted value and multiplying the object with it. Then returns
 * the result in GeneralRational form.
 * @param gn GeneralNumber we wanted to divide the GeneralRational with
 * @return Pointer to the quotient in GeneralRational form
 */
GeneralNumber* GeneralRational::divide(GeneralNumber* gn) const {
  GeneralRational* converted = gn->toGeneralRational();
  long quotient_top;
  long quotient_bottom;

  quotient_top = this->top * converted->bottom;
  quotient_bottom = this->bottom * converted->top;

  GeneralRational* g = new GeneralRational(quotient_top, quotient_bottom);

  g->toCanonicalForm();
  
  return g;
}



/** Default constructor for GeneralDouble 
*/
GeneralDouble::GeneralDouble() {
  value = 0.0; // Default value is a double zero
}

/** Constructor for GeneralDouble
 * @param value Decimal Number to store in the object
 */
GeneralDouble::GeneralDouble(double value) {
  this->value = value;
  // "this->value" means the field inside the object.
  // Just "value" means the parameter.
}

// See header comment in GeneralNumber 
char* GeneralDouble::toString() const {
  // Allocate enough space for largest possible number.
  char* rep = (char*) malloc(MAX_DIGITS_IN_DOUBLE + 1);

  sprintf(rep, "%f", value); // convert to printable form.
  return rep;
}

/** Demonstrates a non-virtual function.
 * @return Freshly-allocated C-stype string
 */
char* GeneralDouble::foo() const {
  char* rep = strdup("This is the output of foo() for GeneralDouble!");
  return rep;
}

/** Generates an equivalent GeneralLong
 * @return Pointer to a freshly-allocated GeneralLong object
 */
GeneralLong* GeneralDouble::toGeneralLong() const {
  GeneralLong* g = new GeneralLong(value); // Very simple!
  return g;
}

/** Generates an equivalent GeneralRational
 * @return Pointer to a freshly-allocated GeneralRational object
 */
GeneralRational* GeneralDouble::toGeneralRational() const {
  GeneralRational* g = new GeneralRational(value, 1L);
  // Slightly more complicated!
  return g;
}

/** Generates an equivalent GeneralDouble
 * @return Pointer to a freshly-allocated GeneralDouble object
 */
GeneralDouble* GeneralDouble::toGeneralDouble() const {
  GeneralDouble* g = new GeneralDouble(value); // Very simple!
  return g;
}


/** Converts any GeneralNumber to GeneralDouble and
 * then adds the value of the object it is invoked
 * on to the value found in the object it converted
 * Then returns generates a GeneralDouble of the sum
 * @param gn GeneralNumber we want added to the GeneralLong
 * @return Pointer to the sum in GeneralDouble form
 */
GeneralNumber* GeneralDouble::add(GeneralNumber* gn) const {
  GeneralDouble* converted = gn->toGeneralDouble();
  
  double sum = this->value + converted->value;

  GeneralDouble* g = new GeneralDouble(sum);

  return g;
  
}


/** Converts any GeneralNumber to GeneralDouble and
 * then subtracts the value of the object it is invoked
 * on to the value found in the object it converted
 * Then returns generates a GeneralNumber of the difference
 * @param gn GeneralNumber we want subtracted from the GeneralDouble
 * @return Pointer to the sum in GeneralDouble form
 */
GeneralNumber* GeneralDouble::subtract(GeneralNumber* gn) const {
  GeneralDouble* converted = gn->toGeneralDouble();
  
  double difference = this->value - converted->value;

  GeneralDouble* g = new GeneralDouble(difference);

  return g;
  
}


/** Converts any GeneralNumber to GeneralDouble and
 * then multiplies the value of the object it is invoked
 * on to the value found in the object it converted
 * Then returns generates a GeneralDouble of the product
 * @param gn GeneralNumber we want multiplied to the GeneralDouble
 * @return Pointer to the product in GeneralDouble form
 */
GeneralNumber* GeneralDouble::multiply(GeneralNumber* gn) const {
  GeneralDouble* converted = gn->toGeneralDouble();
  
  double product = this->value * converted->value;

  GeneralDouble* g = new GeneralDouble(product);

  return g;
  
}


/** Converts any GeneralNumber to GeneralDouble and
 * then divides the value of the object it is invoked
 * on to the value found in the object it converted
 * Then returns generates a GeneralSouble of the quotient
 * @param gn GeneralNumber we want to divide the GeneralDouble with
 * @return Pointer to the quotient in GeneralDouble form
 */
GeneralNumber* GeneralDouble::divide(GeneralNumber* gn) const {
  GeneralDouble* converted = gn->toGeneralDouble();
  
  double quotient = this->value / converted->value;

  GeneralDouble* g = new GeneralDouble(quotient);

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









