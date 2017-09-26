Adonay Resom (azresom@wpi.edu)

DESCRIPTION OF FILES/PROGRAMS

leap.c - This program consumes a year input through the command line
	and figures out of that year is leap year or not. The program
	only accepts years 1752 and after because the United States 
	adopted the Gregorian Calenday officially that year. The program
	mainly uses nested if statments to figure out of the given year
	was infact a leap year.

num.c - This program consumes several arguments from the command line,
	converts them to integer values, and store them in array format.
	Then with the help of its helper program (analyzer.c) it calculates
	the average of the elements of the array it created. The helper
	also enables it to find the elements with the highest and lowest values.

analyzer.c - This program contains a function which is used by the main
	program, num.c. The function accepts two arguments. An array 
	and its size. The functions then calculates the average of the array's 
	elements, as well as figures out the elements with the highest
	and lowest values. It then prints out the findings. The function uses
	a for loop to add and compare array elements.

	MAX_GRADES = 5

connect.h - this header files enables the link between num.c and analyzer.c.

makefile - this file contains instruction on how to compile, link, and run
	 the programs. It contains instructions on how to combine num.c,
	analyzer.c, and connect.h files and create an executable file.

LINKING AND COMPILING

"num.c" and "analyzer.c" are linked in the makefile file. Both programs' have
two dependencies to create their object codes: the program itself and the
header file "connecter.h". Then the executable file "num" was created using 
those two object code files: num.o and analyzer.o. To run the program "num" 
go to the assignment root directory and enter the command make. Then 
enter ./num arg1 arg2 ... to use the program.
 
leap.c is converted to object code and that object code is used to create
an executable. leap.c also uses the forman ./leap year_input , once you use
the make comand on the assignments root directory using command line.


TEST DATA (MAX_GRADES = 5)

Test 			Result
./leap 1802 		1802 is not a leap year
./leap 1900		1900 ia not a leap year
./leap 2000		2000 is a leap year
./leap 1400		1502 is not a valid year input. The program is
			not designed to test years before 1752(G.C)


./num 1 2 3		The average of the elements of the array is 2
			The element with the highest value is 3
			The element with the lowest value is 1

./num 54 85 68 25 85	The average of the elements of the array is 63
			The element with the highest value is 85
			The element with the lowest value is 25	

./num 1 2 3 4 5 6	You have entered more than the allowed number of grades. Only 5 grades have been registered

./num 0 0 0 0 0		The average of the elements of the array is 0
			The element with the highest value is 0
			The element with the lowest value is 0