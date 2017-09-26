Adonay Resom (azresom@wpi.edu)

DESCRIPTION OF FILES/PROGRAMS

calc.cpp - This program contains a main function. It is used to create a calculator that uses
	 the GeneralNumber subclasses as its way of storing and processing numbers. It uses
	 the functions start_calculator() and calculate() to ask user input, process them, and
	 return a result.
	 
gnparse.cpp - This file contains a function called parse that takes user input in string form
	    and creates an object from the class that matches the number from input.


gntest.cpp - This program contains a main function. This program is used to demostrate
	the class GeneralNumber and its subclasses. I have added code to it to demostrate
	the functions toCanonicalForm and add() that are parts of the class GeneralRational
	and GeneralNumber respectively.

GeneralNumber.cpp - This file contains all the constructors and methods related to the class
	GeneralNumber and its subclasses GeneralDouble, GeneralLong and GeneralRational. It
	also contains helper functions gcd(a, b) and lcd(a, b) which help me construct the
	functions toCanonicalForm() and add(), subtract(), multiply()m and divide().

GeneralNumber.h - this header files enables the link between gntest.cpp and GeneralNumber.cpp
	Contains definition and protypes for all classes. Also contains all the methods for 
	

makefile - this file contains instruction on how to compile, link, and run
	 the programs. It contains instructions on how to combine gntest.cpp file with
	with GeneralNumber.cpp. And also links .h files with their respective
	.c files. It also creates the executable file "gntest" 

Doxyfile - Contains instructions for doxygen documentation generation

LINKING AND COMPILING

"calc.cpp" "gnparse.cpp", "GeneralNumber.cpp", "gntest.cpp" and "GeneralNumber.h"
are linked in the makefile file. All .c programs' have dependencies in the makefile
to create their object codes. Most time the program itself and the header files are
used as dependencies. Then the executable file "calc" and "gntest" gets created using
the two object code files gntest.o and GeneralNumber.o. To  run the executable file
go to the assignment's root directory and enter the command make. Then enter ./
followed by the name of the executables.
In this case ./calc to use the program.



TEST DATA

WHEN USER ENTERS BLANK SPACE

Enter first number (blank to exit): 
End of program.


WHEN USER ENTERS INVALID ARGUMENTS (NUMBERS)

Enter first number (blank to exit): jdksaljdkl

Enter first number (blank to exit):


WHEN USER ENTERS INVALID ARGUMENTS (OPERATORS)

Enter first number (blank to exit): 2

Enter second number: 3

Enter operator: &

Invalid Operator. Use +, -, *, or /. Enter an operator again: 


WITH GENERALLONG AND GENERALLONG

Addition:

Enter first number (blank to exit): 2

Enter second number: 3

Enter operator: +

2 + 3 = 5
