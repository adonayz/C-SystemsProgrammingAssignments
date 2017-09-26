/** Class to define a queue; each entry can hold a pointer to anything.
 */
class Queue {
 public:
  // Fields:
  void **head; // Pointer to head of the queue
  void **tail;  // Pointer to tail of the queue
  void **wrap; //Pointer to indicate when queue wraps around
  int cells_used; // Currently used number of cells
  int max_cells; // Size of queue

  // Function prototypes
  Queue (int max_cells);
  ~Queue();
  int enqueue(void *ptr);
  void* dequeue();
  void* peek();
};


