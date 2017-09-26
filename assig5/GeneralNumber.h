
// Maximum number of digits in a long integer, including possible sign
// Not necessarily portable -- this works for 64-bit longs.
#define MAX_DIGITS_IN_LONG (20)
#define MAX_DIGITS_IN_DOUBLE (20)
#define MAX_DIGITS_OR_CHARACTERS_ENTERED (20)
			      
// Class "prototypes" to solve the forward reference problem:
class GeneralNumber;
class GeneralLong;
class GeneralRational;
class GeneralDouble;
/***************************************/

// The parent class:

class GeneralNumber {
 public:
  GeneralNumber();
  virtual char* toString() const= 0;
  char* foo() const; // Not a virtual function!
  virtual GeneralLong* toGeneralLong() const = 0;
  virtual GeneralRational* toGeneralRational() const = 0;
  virtual GeneralDouble* toGeneralDouble() const = 0;
  virtual GeneralNumber* add(GeneralNumber* g) const = 0;
  virtual GeneralNumber* subtract(GeneralNumber* g) const = 0;
  virtual GeneralNumber* multiply(GeneralNumber* g) const = 0;
  virtual GeneralNumber* divide(GeneralNumber* g) const = 0;
  static GeneralNumber* parse(const char* s);
};
/***************************************/

// Define the various subclasses:

class GeneralLong: public GeneralNumber {
 public:
  GeneralLong();
  GeneralLong(long value);
  char* toString() const;
  char* foo() const; // Not a virtual function!
  GeneralLong* toGeneralLong() const;
  GeneralRational* toGeneralRational() const;
  GeneralDouble* toGeneralDouble() const;
  GeneralNumber* add(GeneralNumber* gn) const;
  GeneralNumber* subtract(GeneralNumber* gn) const;
  GeneralNumber* multiply(GeneralNumber* gn) const;
  GeneralNumber* divide(GeneralNumber* gn) const;
  
 private:
  long value; // This holds the value of the number.
};

class GeneralRational: public GeneralNumber {
 public:
  GeneralRational();
  GeneralRational(long top, long bottom);
  char* toString() const;
  char* foo() const; // Not a virtual function!
  GeneralLong* toGeneralLong() const;
  GeneralRational* toGeneralRational() const;
  GeneralDouble* toGeneralDouble() const;
  void toCanonicalForm();
  GeneralNumber* add(GeneralNumber* gn) const;
  GeneralNumber* subtract(GeneralNumber* gn) const;
  GeneralNumber* multiply(GeneralNumber* gn) const;
  GeneralNumber* divide(GeneralNumber* gn) const;
  
 private:
  long top; // This holds the top (numerator)
  long bottom; // This holds the bottom (denominator)
};

class GeneralDouble: public GeneralNumber {
 public:
  GeneralDouble();
  GeneralDouble(double value);
  char* toString() const;
  char* foo() const;// Not a virtual function!
  GeneralLong* toGeneralLong() const;
  GeneralRational* toGeneralRational() const;
  GeneralDouble* toGeneralDouble() const;
  GeneralNumber* add(GeneralNumber* gn) const;
  GeneralNumber* subtract(GeneralNumber* gn) const;
  GeneralNumber* multiply(GeneralNumber* gn) const;
  GeneralNumber* divide(GeneralNumber* gn) const;

 private:
  double value;
};

long find_gcd(long a, long b); //to calcuate Greatest Common Divisor
long find_lcd(long a, long b); //to calculate Least Common Denominator

int start_calculator(); //start calculator function
GeneralNumber* calculate(GeneralNumber* fnum, GeneralNumber* snum, char* oprtr);
