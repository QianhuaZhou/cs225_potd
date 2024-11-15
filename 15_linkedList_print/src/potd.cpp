#include "potd.h"
#include <iostream>

using namespace std;

string stringList(Node *head) {
    // your code here!
   
    Node* cur = head;
    string s;
    int count = 1;
    if(head == nullptr) return "Empty list";
    s =  "Node 0: " + to_string(cur->data_);
    cur = cur->next_;
    while(cur!= nullptr){
        s = s + " -> Node " + to_string(count) + ": " + to_string(cur->data_);
        count++;
        cur = cur->next_;
    }
    return s;
}
