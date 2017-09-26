#include <stdlib.h>
#include <stdio.h>
#include "objstack.h"
#include "foo.h"

using namespace std;

int main() {
  const int max_entries = 5; // size of stack
  Foo* new_foo1;
  Foo* new_foo2; 
  Foo* returned_foo;
  char *ts; // Points to string returned by toString();
  
  // First, create a stack
  Stack *new_stack = new Stack(max_entries);

  // Allocate a Foo and push it onto the stack.
  new_foo1 = new Foo(6, 14.79);
  ts = new_foo1->toString();
  printf("\nPushing: %s\n", ts);
  free(ts);
  new_stack->push((void *) new_foo1);

  // Allocate another Foo and push it onto the stack.
  new_foo2 = new Foo(217, 3.14159);
  ts = new_foo2->toString();
  printf("Pushing: %s\n", ts);
  free(ts);
  new_stack->push((void *) new_foo2);

  // Peek at the top of the stack
  returned_foo = (Foo *) new_stack->peek();
  ts = returned_foo->toString();
  printf("Peeked: %s\n", ts);
  free(ts); // Do not free returned_foo, since we are still using it!

  // Retrieve the Foos and print them.
  returned_foo = (Foo *) new_stack->pop();
  if (!returned_foo) {
    printf("Stack is empty!\n");
  } else {
    ts = returned_foo->toString();
    printf("Popped: %s\n", ts);
    free(ts);
    delete(returned_foo);
  }
  
  returned_foo = (Foo *) new_stack->pop();
  if (!returned_foo) {
    printf("Stack is empty!\n");
  } else {
    ts = returned_foo->toString();
    printf("Popped: %s\n", ts);
    free(ts);
    delete(returned_foo);
  }

  //LAB
  Foo* lab_foo1;
  Foo* lab_foo2;
  Foo* lab_foo3;
  Foo* lab_foo4; 
  Foo* lab_foo5;
  Foo* lab_foo6; 
  
  printf("\n\nLAB 6\n");

  //PUSHING FOOS
  lab_foo1 = new Foo(100, 0.355);
  ts = lab_foo1->toString();
  printf("Pushing: %s\n", ts);
  free(ts);
  new_stack->push((void *) lab_foo1);

  lab_foo2 = new Foo(8, 11.25);
  ts = lab_foo2->toString();
  printf("Pushing: %s\n", ts);
  free(ts);
  new_stack->push((void *) lab_foo2);

  lab_foo3 = new Foo(420, 8.0);
  ts = lab_foo3->toString();
  printf("Pushing: %s\n", ts);
  free(ts);
  new_stack->push((void *) lab_foo3);


  //POPPING FOOS
  returned_foo = (Foo *) new_stack->pop();
  if (!returned_foo) {
    printf("Stack is empty!\n");
  } else {
    ts = returned_foo->toString();
    printf("Popped: %s\n", ts);
    free(ts);
    delete(returned_foo);
  }

  returned_foo = (Foo *) new_stack->pop();
  if (!returned_foo) {
    printf("Stack is empty!\n");
  } else {
    ts = returned_foo->toString();
    printf("Popped: %s\n", ts);
    free(ts);
    delete(returned_foo);
  }

  
  returned_foo = (Foo *) new_stack->pop();
  if (!returned_foo) {
    printf("Stack is empty!\n");
  } else {
    ts = returned_foo->toString();
    printf("Popped: %s\n", ts);
    free(ts);
    delete(returned_foo);
  }

  //PUSING ONE MORE
  lab_foo4 = new Foo(15, 21.5);
  ts = lab_foo4->toString();
  printf("Pushing: %s\n", ts);
  free(ts);
  new_stack->push((void *) lab_foo4);

   //POPPING MORE FOOS THAN AVAILABLE

  returned_foo = (Foo *) new_stack->pop();
  if (!returned_foo) {
    printf("Stack is empty!\n");
  } else {
    ts = returned_foo->toString();
    printf("Popped: %s\n", ts);
    free(ts);
    delete(returned_foo);
  }

  returned_foo = (Foo *) new_stack->pop();
  if (!returned_foo) {
    printf("Stack is empty!\n");
  } else {
    ts = returned_foo->toString();
    printf("Popped: %s\n", ts);
    free(ts);
    delete(returned_foo);
  }


  
  
  printf("\nTrying to push more than 5 elements (Stack is now completely empty))\n");

   lab_foo1 = new Foo(100, 0.355);
  ts = lab_foo1->toString();
  printf("Pushing: %s\n", ts);
  free(ts);
  new_stack->push((void *) lab_foo1);

  lab_foo2 = new Foo(8, 11.25);
  ts = lab_foo2->toString();
  printf("Pushing: %s\n", ts);
  free(ts);
  new_stack->push((void *) lab_foo2);

  lab_foo3 = new Foo(420, 8.0);
  ts = lab_foo3->toString();
  printf("Pushing: %s\n", ts);
  free(ts);
  new_stack->push((void *) lab_foo3);

  lab_foo4 = new Foo(78, 26.36);
  ts = lab_foo4->toString();
  printf("Pushing: %s\n", ts);
  free(ts);
  new_stack->push((void *) lab_foo4);

  lab_foo5 = new Foo(2, 0.258);
  ts = lab_foo5->toString();
  printf("Pushing: %s\n", ts);
  free(ts);
  new_stack->push((void *) lab_foo5);

  
  lab_foo6 = new Foo(87, 54.58);
  if (new_stack->push((void *) lab_foo6)) {
    printf("Stack is full. Cannot push more!\n");
  }else{
    ts = lab_foo6->toString();
    printf("Pushing: %s\n", ts);
    free(ts);  
  }
  printf("\nChanged cells_used > max_cell to cells_used + 1 > max_cell \nin push in objstack.cpp\n\n");
  delete(new_stack);

  return 0;
}
