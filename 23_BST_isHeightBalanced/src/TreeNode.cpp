#include "TreeNode.h"
#include <iostream>
int getHeight(TreeNode* root){
  if(root == nullptr) return 0;
  //getHeight(root->left_);
  //getHeight(root->right_);
  return std::max(getHeight(root->left_), getHeight(root->right_)) + 1;
}

bool isHeightBalanced(TreeNode* root) {
  // your code here
  int left = (left_ == nullptr) ? 0 : getHeight(root->left_);//can't directly return 0
  int right = (getHeight(root->right_);
  if(left == right) return true;
  return false;
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

