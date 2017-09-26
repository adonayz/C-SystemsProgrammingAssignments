all:ctest main

# Executable depends on the two object files
ctest: ctest.o mystring.o 
	gcc -g ctest.o mystring.o -o ctest

# Object file depends on source and header files
ctest.o: ctest.c mystring.h 
	gcc -g -c ctest.c

# Executable depends on the two object files
main: main.o mystring.o structs.o
	gcc -g main.o mystring.o structs.o -o main

# Object file depends on source and header files
main.o: main.c mystring.h structs.h
	gcc -g -c main.c

# Object file depends on source and header files
mystring.o: mystring.c mystring.h 
	gcc -g -c mystring.c


# Object file depends on source and header files
structs.o: structs.c structs.h 
	gcc -g -c structs.c

clean: 
	rm -f *.o
	rm -f ctest main

# Typing "make docs" will generate Doxygen files, set proper permissions,
# and copy into ~/public_html/cs2303assig3 .
docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2303assig3
