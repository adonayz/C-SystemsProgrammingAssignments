all: objstacktest

objstacktest: objstacktest.o objstack.o foo.o
	g++ -g objstacktest.o objstack.o foo.o -o objstacktest

objstack.o: objstack.cpp objstack.h
	g++ -g -c objstack.cpp

objstacktest.o: objstacktest.cpp objstack.h foo.h
	g++ -g -c objstacktest.cpp

foo.o: foo.cpp foo.h
	g++ -g -c foo.cpp

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2303assig6

clean:
	rm -f *.o
	rm -f objstacktest
