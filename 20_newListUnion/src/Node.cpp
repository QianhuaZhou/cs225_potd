#include "Node.h"
#include <iostream>

/** Create a new node and add it to the list, while keeping the list sorted.
*/
Node *insertSorted(Node *first, int data) {
    // your code here
    
    Node* n = new Node();
    n->data_ = data;
    n->next_ = nullptr;
    if(first == nullptr){
        return n;
    }
    if(first->data_ == data){
        delete n;
        return first;
    }
    if(first->data_ > data){
        n->next_ = first;
        return n;
    }
    
    //first->data_ < data
    Node* cur = first;
    while(cur->next_ != nullptr){
        if(cur->next_->data_ == data){
            delete n;
            return first;
        }
        if(cur->next_->data_ > data){
            n->next_ = cur->next_;
            cur->next_ = n; 
            return first;     
        }
        cur = cur->next_;
    }
    cur->next_ = n;
    return first;
}

/** Creates a new list (containing new nodes, allocated on the heap)
	that contains the set union of the values in both lists.
*/
Node *listUnion(Node *first, Node *second) {
    Node *out = NULL;

    while (first != NULL) {
        // your code here
        // hint: call insertSorted and update l1
        out = insertSorted(out, first->data_);
        first = first->next_;
    }
    while (second != NULL) {
        // your code here
        out = insertSorted(out, second->data_);
        second = second->next_;
    }

    return out;
}

Node::Node() {
    numNodes++;
}

Node::Node(const Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
