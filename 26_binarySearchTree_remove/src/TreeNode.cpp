#include "TreeNode.h"
#include <iostream>

TreeNode *& find(TreeNode*& root, int key){
  if(root == nullptr || root->val_ == key) return root;
  if(root->val_ > key) return find(root->left_, key);
  return find(root->right_, key);
}

TreeNode * deleteNode(TreeNode* root, int key) {
  // your code here
  if(root == nullptr) return nullptr;
  TreeNode *& loc = find(root, key);
  if(loc == nullptr) return root;
  if(loc->left_ == nullptr && loc->right_ == nullptr){
    delete loc;
    loc = nullptr;
  }else if(loc->left_ != nullptr && loc->right_ != nullptr){
    //find iop, call delteNode
    TreeNode* iop = loc->right_;
    while(iop->left_ != nullptr) iop = iop->left_;
    loc->val_ = iop->val_;
    loc->right_ = deleteNode(loc->right_, iop->val_);//the removed value is no leaf, need to reconnect
  }else{
    TreeNode* temp = loc;
    loc = (loc->left_ != nullptr) ? loc->left_ : loc->right_;
    delete temp;
  }
  return root;
}

void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
