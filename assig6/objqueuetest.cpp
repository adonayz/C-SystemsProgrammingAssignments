#include <stdlib.h>
#include <stdio.h>
#include "objqueue.h"
#include "foo.h"

using namespace std;

int main() {
  const int max_entries = 5; // size of queue
  Foo* new_foo1;
  Foo* new_foo2; 
  Foo* returned_foo;
  char *ts; // Points to string returned by toString();
  
  // First, create a queue
  Queue *new_queue = new Queue(max_entries);

  Foo* lab_foo1;
  Foo* lab_foo2;
  Foo* lab_foo3;
  Foo* lab_foo4; 
  Foo* lab_foo5;
  Foo* lab_foo6; 

  
  printf("\n\nTo demonstrate how queue wraps around (adding more foos that allowed by max_cells, 6)\n");

  
  
  printf("\nTrying to enqueue more than 5 elements (queue is now completely empty))\n");

   lab_foo1 = new Foo(100, 0.355);
  ts = lab_foo1->toString();
  printf("enqueueing: %s\n", ts);
  free(ts);
  new_queue->enqueue((void *) lab_foo1);

  lab_foo2 = new Foo(8, 11.25);
  ts = lab_foo2->toString();
  printf("enqueueing: %s\n", ts);
  free(ts);
  new_queue->enqueue((void *) lab_foo2);

  lab_foo3 = new Foo(420, 8.0);
  ts = lab_foo3->toString();
  printf("enqueueing: %s\n", ts);
  free(ts);
  new_queue->enqueue((void *) lab_foo3);

  lab_foo4 = new Foo(78, 26.36);
  ts = lab_foo4->toString();
  printf("enqueueing: %s\n", ts);
  free(ts);
  new_queue->enqueue((void *) lab_foo4);

  lab_foo5 = new Foo(2, 0.258);
  ts = lab_foo5->toString();
  printf("enqueueing: %s\n", ts);
  free(ts);
  new_queue->enqueue((void *) lab_foo5);

  
  lab_foo6 = new Foo(87, 54.58);
  if (new_queue->enqueue((void *) lab_foo6)) {
    printf("queue is full. Cannot enqueue more!\n");
  }else{
    ts = lab_foo6->toString();
    printf("enqueueing: %s\n", ts);
    free(ts);  
  }

  returned_foo = (Foo *) new_queue->dequeue();
  if (!returned_foo) {
    printf("queue is empty!\n");
  } else {
    ts = returned_foo->toString();
    printf("dequeued: %s\n", ts);
    free(ts);
    delete(returned_foo);
  }

  returned_foo = (Foo *) new_queue->dequeue();
  if (!returned_foo) {
    printf("queue is empty!\n");
  } else {
    ts = returned_foo->toString();
    printf("dequeued: %s\n", ts);
    free(ts);
    delete(returned_foo);
  }

  returned_foo = (Foo *) new_queue->dequeue();
  if (!returned_foo) {
    printf("queue is empty!\n");
  } else {
    ts = returned_foo->toString();
    printf("dequeued: %s\n", ts);
    free(ts);
    delete(returned_foo);
  }

  returned_foo = (Foo *) new_queue->dequeue();
  if (!returned_foo) {
    printf("queue is empty!\n");
  } else {
    ts = returned_foo->toString();
    printf("dequeued: %s\n", ts);
    free(ts);
    delete(returned_foo);
  }

  
  return 0;
}
