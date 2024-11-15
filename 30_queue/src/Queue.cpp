#include "Queue.h"



// `int size()` - returns the number of elements in the stack (0 if empty)
int Queue::size() const {
  return l.size();
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Queue::isEmpty() const {
  return l.empty();
}

// `void enqueue(int val)` - enqueue an item to the queue in O(1) time
void Queue::enqueue(int value) {
  l.push_back(value);
}

// `int dequeue()` - removes an item off the queue and returns the value in O(1) time
int Queue::dequeue() {
 int temp = l.front();
 l.pop_front();
 return temp;
}
