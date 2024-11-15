#include "TreeNode.h"
#include <iostream>

int getHeight(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = getHeight(root->left_);
    int right = getHeight(root->right_);
    return std::max(left, right) + 1;
}

TreeNode* findLastUnbalanced(TreeNode* root) {
    if (root == nullptr) return nullptr;

    // Check if current node is unbalanced
    int leftHeight = getHeight(root->left_);
    int rightHeight = getHeight(root->right_);
    int balanceFactor = rightHeight - leftHeight;

    // If the current node is unbalanced, continue to search further down
    if (balanceFactor > 1 || balanceFactor < -1) {
        TreeNode* leftUnbalanced = findLastUnbalanced(root->left_);
        TreeNode* rightUnbalanced = findLastUnbalanced(root->right_);
        return rightUnbalanced != nullptr ? rightUnbalanced : (leftUnbalanced != nullptr ? leftUnbalanced : root);
    }

    // Recursively search for unbalanced nodes in both left and right subtrees
    TreeNode* leftUnbalanced = findLastUnbalanced(root->left_);
    TreeNode* rightUnbalanced = findLastUnbalanced(root->right_);

    // Return the last unbalanced node found, if any
    if (rightUnbalanced != nullptr) return rightUnbalanced;
    if (leftUnbalanced != nullptr) return leftUnbalanced;

    return nullptr;
}


void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

