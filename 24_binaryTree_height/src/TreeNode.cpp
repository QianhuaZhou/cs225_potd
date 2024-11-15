#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {
  int left = (left_ == nullptr) ? 0 : left_->getHeight() + 1;
  int right = (right_ == nullptr) ? 0 : right_->getHeight() + 1;
  return std::max(left, right);
}
