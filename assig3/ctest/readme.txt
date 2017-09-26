Adonay Resom (azresom@wpi.edu)

DESCRIPTION OF FILES/PROGRAMS

ctest.c - This program generates an array full of consecutive numbers in the
	form of doubles. It has a constant SAMPLE_INT_ARRAY_SIZE which equals
	10 is used to limit the size of the array created.

main.c - This program takes in arguments from the user, converts those arguments
	to integer type, adds the converted integers to an array, prints that
	array, sorts the same array, and prints it again. This program uses
	function from other source files. The function include print_int_array,
	sort_ascending, and save array. It has a constant SAMPLE_INT_ARRAY_SIZE which equals
	10 is used to limit the size of the array created.

mystring.c - This program includes functions such as random_integer and random_array
	which create random integers given a specified maximum, and generates an array of
	random integers. It also includes an importnant function called sort_ascending that
	sorts integer arrays in ascending order using the buble sort algorithm.

structs.c- This program includes functions print_int_array and print_double_array
	which are used by other main programs. It also 
	includes the function save_array that is used to take user input from command
	line and store it into an array.

structs.h - this header files enables the link between structs.c with main.c and ctest.c

mystring.h - this header files enables the link between mystring.c
	 with ctest.c and main.c

makefile - this file contains instruction on how to compile, link, and run
	 the programs. It contains instructions on how to combine .c files with
	helper functions in other .c files. And link .h files with their respective
	.c files and create also create executable files for at.c, at2.c, at3.c.

LINKING AND COMPILING

"main.c", "ctest.c", and "mystring.c" "structs.c" are linked
in the makefile file. All .c programs' have dependencies to create their
object codes. Most time the program itself and the header files are used as
dependencies. Then the executable files "main", "ctest" get created 
using the two object code files. To run the executables go to the assignment 
root directory and enter the command make. Then enter ./ followed by the name
of the executables.



TEST DATA

ALL TEST DATA SHOWED WHEN RUNNING THE PROGRAMS. TESTS IN FUNCTION IN OTHER WORDS