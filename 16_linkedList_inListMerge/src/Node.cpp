#include "Node.h"

void mergeList(Node *first, Node *second) {
  // your code here!
  if(first == nullptr) return;
  Node* fCurr = first;
  Node* sCurr = second;
  if(fCurr != nullptr) fCurr = fCurr->next_;
  if(sCurr != nullptr){
    first->next_ = sCurr;
    first = first->next_;
    sCurr = sCurr->next_;
  }
  while(fCurr != nullptr && sCurr != nullptr){
    first->next_ = fCurr;
    fCurr = fCurr->next_;
    first = first->next_;

    first->next_ = sCurr;
    sCurr = sCurr->next_;
    first = first->next_;
  }
  if(sCurr == nullptr ){
    while(fCurr != nullptr){
    first->next_ = fCurr;
    fCurr = fCurr->next_;
    first = first->next_;
    }
  }
  if(fCurr == nullptr ){
    while(sCurr != nullptr){
        first->next_ = sCurr;
        sCurr = sCurr->next_;
        first = first->next_;
    }
   
  }
  
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
