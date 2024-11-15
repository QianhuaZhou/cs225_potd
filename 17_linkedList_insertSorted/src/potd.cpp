#include "potd.h"
#include <iostream>

void insertSorted(Node **head, Node *insert) {
  // your code here!
  if(*head == nullptr){
    *head = insert;
    return;
  }
  if((*head)->data_ >= insert->data_){
    insert->next_ = *head;
    *head = insert;
    return;
  }
  Node* h = *head;//cannot directly use head to tranverse it
  while((h->next_ != nullptr && h->next_->data_ < insert->data_)){//here should use ->next, to store the previous value to connect to insert
    h= h->next_;
  }
  insert->next_ = h->next_;
  h->next_ = insert;
    
}

