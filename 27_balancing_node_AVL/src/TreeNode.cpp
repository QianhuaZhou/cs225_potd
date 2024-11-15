#include "TreeNode.h"

TreeNode::RotationType balanceTree(TreeNode*& subroot) {
	// Your code here
  if(leftHeavy(subroot)){
    if(leftHeavy(subroot->left_)) return TreeNode::right;
    return TreeNode::leftRight;
  }

  if(rightHeavy(subroot->right_)) return TreeNode::left;
  return TreeNode::rightLeft;
}
