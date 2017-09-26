Adonay Resom (azresom@wpi.edu)

DESCRIPTION OF FILES/PROGRAMS

at.c - This program generates an array full of consecutive numbers in the
	form of doubles. It has a constant SAMPLE_INT_ARRAY_SIZE which equals
	10 is used to limit the size of the array created.

at2.c - This program takes in arguments from the user, converts those arguments
	to integer type, adds the converted integers to an array, prints that
	array, sorts the same array, and prints it again. This program uses
	function from other source files. The function include print_int_array,
	sort_ascending, and save array. It has a constant SAMPLE_INT_ARRAY_SIZE which equals
	10 is used to limit the size of the array created.

at3.c - This program creates an array of randomly generated numbers and prints
	the array. It then sorts the same array in ascending order and prints 
	it again. It has a constants MAXIMUM and RANDOM_ARRAY_SIZE which equals
	15 and 10 respectively, and are used to limit the size of the array and 
	maximum value of randomly genrated number.

sort_ascending.c - This program includes functions such as random_integer and random_array
	which create random integers given a specified maximum, and generates an array of
	random integers. It also includes an importnant function called sort_ascending that
	sorts integer arrays in ascending order using the buble sort algorithm.

print_arrays.c - This program includes functions print_int_array and print_double_array
	which are used by other main programs (at, at2, at3) to print arrays. It also 
	includes the function save_array that is used to take user input from command
	line and store it into an array.

sort_ascending.h - this header files enables the link between sort_ascending.c with at2.c and at3.c.

print_arrays.h - this header files enables the link between print_arrays.c
	 with at, at2.c and at3.c.

makefile - this file contains instruction on how to compile, link, and run
	 the programs. It contains instructions on how to combine .c files with
	helper functions in other .c files. And link .h files with their respective
	.c files and create also create executable files for at.c, at2.c, at3.c.

LINKING AND COMPILING

"at.c", "at2.c", "at3.c" and "print_arrays.c" "sort_ascending.h" are linked
in the makefile file. All .c programs' have dependencies to create their
object codes. Most time the program itself and the header files are used as
dependencies. Then the executable files "at.c", "at2.c", "at3.c" get created 
using the two object code files. To run the executables go to the assignment 
root directory and enter the command make. Then enter ./ followed by the name
of the executables. For eg: ./at2 arg1 arg2 ...  or ./at3 to use the programs.



TEST DATA

Test			Result
./at			0.000000
			1.000000
			2.000000
			3.000000
			4.000000
			5.000000
			6.000000
			7.000000
			8.000000
			9.000000

./at2 76 54 69 34 23	The following are numbers you entered in the order which you entered them
			76
			54
			69
			34
			23
			The following are those numbers you entered sorted in ascending order
			23
			34
			54
			69
			76
		
./at2			Must enter a number on the command line!

./at2  2 3 4 		You have entered more than the allowed number of argumennts. Only 11 numbers have been stored
	5 6 7 
	8 9 0 
	9 8 4

./at3			The following are randomly generated numbers 
			that are NOT sorted
			19
			11
			8
			7
			2
			16
			9
			1
			9
			0
			The following are randomly generated numbers
			that are sorted in ascending order
			0
			1
			2
			7
			8
			9
			9
			11
			16
			19
