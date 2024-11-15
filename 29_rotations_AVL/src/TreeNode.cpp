#include "TreeNode.h"
#include <algorithm>

void rightRotate(TreeNode* root) {
    // Your code here
    TreeNode *y = root->left_;
    y->parent_ = root->parent_;
    root->left_ = y->right_;
    if(y->right_){y->right_->parent_ = root;}
    y->right_ = root;
    root->parent_ = y;
}


void leftRotate(TreeNode* root) {

    // your code here
    TreeNode *y = root->right_;
    y->parent_ = root->parent_;
    root->right_ = y->left_;
    if(y->left_){y->left_->parent_ = root;}
    y->left_ = root;
    root->parent_ = y;
}



void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

