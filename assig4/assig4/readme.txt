Adonay Resom (azresom@wpi.edu)

DESCRIPTION OF FILES/PROGRAMS

gntest.cpp - This program contains the main function. This program is used to demostrate
	the class GeneralNumber and its subclasses. I have added code to it to demostrate
	the functions toCanonicalForm and add() that are parts of the class GeneralRational
	and GeneralNumber respectively.

GeneralNumber.cpp - This file contains all the constructors and methods related to the class
	GeneralNumber and its subclasses GeneralLong and GeneralRational. It also contains 
	helper functions gcd(a, b) and lcd(a, b) which help me construct the functions 
	toCanonicalForm() and add().t is used to take user input from command
	line and store it into an array.

GeneralNumber.h - this header files enables the link between gntest.cpp and GeneralNumber.cpp
	Contains definition and protypes for all classes. Also contains all the methods for 
	

makefile - this file contains instruction on how to compile, link, and run
	 the programs. It contains instructions on how to combine gntest.cpp file with
	with GeneralNumber.cpp. And also links .h files with their respective
	.c files. It also creates the executable file "gntest" 

Doxyfile - Contains instructions for doxygen documentation generation

LINKING AND COMPILING

"GeneralNumber.cpp", "gntest.cpp" and "GeneralNumber.h" are linked
in the makefile file. All .c programs' have dependencies in the makefile
to create their object codes. Most time the program itself and the header
files are used as dependencies. Then the executable file "gntest" gets
created using the two object code files gntest.o and GeneralNumber.o. To 
run the executable file go to the assignment's root directory and enter
the command make. Then enter ./ followed by the name of the executables.
In this case ./gntest to use the program.



TEST DATA

Demostrating the use of toCanonicalForm()


Before using toCanonicalForm():
[4000 / 3000]
After using toCanonicalForm():
[4 / 3]

Before using toCanonicalForm():
[4000 / -3000]
After using toCanonicalForm():
[-4 / 3]

Before using toCanonicalForm():
[-4000 / -3000]
After using toCanonicalForm():
[4 / 3]

Demostrating the use of the add() function
 
Add General Long onto a General Long
Sum of 2000 and 500 is equal to = 2500

Add General Rational onto a General Long
Sum of 50 and [90 / 6] is equal to = 65

Add General Long onto a General Rational
Sum of [10 / 3] and 20 is equal to = [70 / 3]

Add General Rational onto a General Rational
Sum of [50 / 3] and [30 / 7] is equal to = [440 / 21]
