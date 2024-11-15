#include <vector>
#include "BTreeNode.h"
#include <iostream>

BTreeNode* find(BTreeNode* root, int key) {
    // Your Code Here
  if(root != nullptr){
    int count = 0;
    for(; count < static_cast<int>(root->elements_.size()); count++){
      std::cout << __LINE__ << " " << root->elements_[count] << std::endl;
      if(root->elements_[count] == key) return root;
      if(root->elements_[count] > key){
        if(!root->is_leaf_){
        root = root->children_[count];
        return find(root, key);
        }
        return  nullptr;
      }
    }
    if(!root->is_leaf_) return find(root->children_[count], key);
    return nullptr;
  }
  return nullptr;
}
