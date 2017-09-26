all: treetest randomvaluetree objqueuetest

treetest: treetest.o Tree.o
	g++ -g treetest.o Tree.o -o treetest

randomvaluetree: randomvaluetree.o Tree.o
	g++ -g randomvaluetree.o Tree.o -o randomvaluetree

objqueuetest: objqueuetest.o objqueue.o foo.o
	g++ -g objqueuetest.o objqueue.o foo.o -o objqueuetest

objqueue.o: objqueue.cpp objqueue.h
	g++ -g -c objqueue.cpp

objqueuetest.o: objqueuetest.cpp objqueue.h foo.h
	g++ -g -c objqueuetest.cpp

treetest.o: treetest.cpp Tree.h
	g++ -g -c treetest.cpp

randomvaluetree.o: randomvaluetree.cpp Tree.h
	g++ -g -c randomvaluetree.cpp

Tree.o: Tree.cpp Tree.h
	g++ -g -c Tree.cpp

clean:
	rm -f *.o treetest randomvaluetree objqueuetest

docs:
	doxygen
	chmod a+r,a-x html/*
	cp -p html/* ~/public_html/cs2303assig6

