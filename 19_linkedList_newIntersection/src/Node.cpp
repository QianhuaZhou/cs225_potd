#include "Node.h"
#include <iostream>
using namespace std;

Node *listIntersection(Node *first, Node *second) {
  // your code here
if(first == nullptr || second == nullptr) return nullptr;
  Node* ret = nullptr;//"return ret;" cause a segmentation fault because ret is uninitialized
  Node* tail = nullptr;
  Node* head_f = first;
  Node* head_s = second;
  while(head_f != nullptr){
    head_s = second;
    std::cout << __LINE__ << "outter loop,  head_f->data_" <<  head_f->data_ << std::endl;
    while(head_s != nullptr){
        if(head_f->data_ == head_s->data_){
            if(ret == nullptr){
                ret = new Node();
                ret->data_ = head_f->data_;
                ret->next_ = nullptr;
                tail = ret;
                std::cout << __LINE__ << "inner loop,  ret->data_" <<  ret->data_ << std::endl;
            }else{
                Node* tmp = ret;
                
                    tail->next_ = new Node();
                    tail = tail->next_;
                    tail->data_ = head_f->data_;
                    tail->next_ = nullptr;
                
            }   
            break;
        }
        std::cout << __LINE__ << "inner loop,  head_s->data_ = "   << head_s->data_<< std::endl;
        head_s = head_s->next_;
    }
    head_f = head_f ->next_;
  }
  return ret;
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
