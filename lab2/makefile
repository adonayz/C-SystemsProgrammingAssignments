all: at at2 at3

at: at.o print_arrays.o
	gcc -g --std=gnu89 at.o print_arrays.o -o at

at.o: at.c print_arrays.h
	gcc -g --std=gnu89 -c at.c

at2: at2.o print_arrays.o sort_ascending.o
	gcc -g --std=gnu89 at2.o print_arrays.o sort_ascending.o -o at2

at2.o: at2.c print_arrays.h
	gcc -g --std=gnu89 -c at2.c

at3: at3.o print_arrays.o sort_ascending.o
	gcc -g --std=gnu89 at3.o print_arrays.o sort_ascending.o -o at3

at3.o: at3.c print_arrays.h
	gcc -g --std=gnu89 -c at3.c

print_arrays.o: print_arrays.c print_arrays.h
	gcc -g --std=gnu89 -c print_arrays.c

sort_ascending.o: sort_ascending.c sort_ascending.h
	gcc -g --std=gnu89 -c sort_ascending.c

docs:
	doxygen
	chmod go+r html latex
	cp -p -r html/* ~/public_html/cs2303assig2/

clean:
	rm -f *.o
	rm -f at at2 at3
