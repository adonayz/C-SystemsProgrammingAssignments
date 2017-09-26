#include <stdlib.h>
#include "objqueue.h"

using namespace std;

/** Create a queue by initializing the fields of the object,
 *  including allocating memory to hold the queue entries.
 * @param 
 */
Queue::Queue(int max_cells) {
  // Fill in the struct
  this->max_cells = max_cells; // "this->" needed to speciify field, not param.
  cells_used = 0; // Empty to start

  // Now allocate space for the stack entries.
  this->head = (void **) calloc(sizeof(void *), max_cells);
  if (this->head == NULL) {
    // Should signal an exception
  }

  tail = head;
  wrap = head;
}

/** Destructor: cleans up a Queue object by deleting the memory
 * for holding the queue entries, but not the entries themselves.
 */
Queue::~Queue() {
  free(head); // Free memory block;
}

/** Enqueues/adds a pointer onto a Queue.
 * @param ptr Pointer to be added.
 * @return 0 if successful, 1 if not.
 */
int Queue::enqueue(void *ptr) {
  // Check if stack is already full 
  if (tail == wrap + sizeof(max_cells)) {
    cells_used = max_cells; // Fix the field.
    tail = wrap;
    *tail = ptr;
    tail++;
    return 1; 
  }
    
  // to add to queue tail (enqueu)
  *tail = ptr;  // Store the pointer on the queue
  tail++;       // Point to next free cell 
  cells_used++; 
  return 0;  // Success
}

/** Removes from , and returns it.
 * @return Head of queue, NULL if queue is empty.
 */
void* Queue::dequeue() {
  // Check if queue is empty
  if (cells_used <= 0) {
    cells_used = 0; // Fix the field.
    return NULL;  // queue empty
  }

  // move head pointer
  head++;         // Remember, this points to next free cell
  cells_used--;
  return *(head -1);
}
