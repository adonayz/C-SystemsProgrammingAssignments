
// Maximum number of digits in a long integer, including possible sign
// Not necessarily portable -- this works for 64-bit longs.
#define MAX_DIGITS_IN_LONG (20)

// Class "prototypes" to solve the forward reference problem:
class GeneralNumber;
class GeneralLong;
class GeneralRational;
/***************************************/

// The parent class:

class GeneralNumber {
 public:
  GeneralNumber();
  virtual char* toString() const;
  char* foo() const; // Not a virtual function!
  virtual GeneralLong* toGeneralLong() const;
  virtual GeneralRational* toGeneralRational() const;
  virtual GeneralNumber* add(GeneralNumber* g) const;
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
  GeneralNumber* add(GeneralNumber* gn) const;
  
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
  void toCanonicalForm();
  GeneralNumber* add(GeneralNumber* gn) const;
  
 private:
  long top; // This holds the top (numerator)
  long bottom; // This holds the bottom (denominator)
};

long find_gcd(long a, long b);
long find_lcd(long a, long b);
