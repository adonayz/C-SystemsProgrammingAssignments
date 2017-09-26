all: gntest calc

gntest: gntest.o GeneralNumber.o gnparse.o
	g++ -g gntest.o GeneralNumber.o gnparse.o -o gntest

calc: calc.o GeneralNumber.o gnparse.o
	g++ -g calc.o GeneralNumber.o gnparse.o -o calc

gntest.o: gntest.cpp GeneralNumber.h
	g++ -g -c gntest.cpp

calc.o: calc.cpp GeneralNumber.h
	g++ -g -c calc.cpp

gnparse.o: gnparse.cpp GeneralNumber.h
	g++ -g -c gnparse.cpp

GeneralNumber.o: GeneralNumber.cpp GeneralNumber.h
	g++ -g -c GeneralNumber.cpp

clean:
	rm -f *.o gntest calc

docs:
	doxygen
	chmod a+r,a-x html/*
	cp -p html/* ~/public_html/cs2303assig5

