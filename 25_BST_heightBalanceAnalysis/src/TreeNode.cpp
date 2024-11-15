#include "TreeNode.h"
#include <iostream>
int getHeightBalance(TreeNode* root) {
  // your code here
  return computeHeight(root->left_) - computeHeight(root->right_);
}

int computeHeight(TreeNode* root){
  if(root == nullptr) return 0;
  int left = 0;
  int right = 0;
  if(root->left_ != nullptr) left = computeHeight(root->left_);
  if(root->right_ != nullptr) right = computeHeight(root->right_);
  return 1 + std::max(left, right);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

