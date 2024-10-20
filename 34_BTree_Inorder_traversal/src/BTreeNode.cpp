#include <vector>
#include "BTreeNode.h"


std::vector<int> traverse(BTreeNode* root) {
    // your code here
    std::vector<int> v;
    if(root == nullptr) return v;
    for(unsigned int i = 0; i < root->elements_.size(); ++i){
        if(!root->is_leaf_){
            std::vector<int> childVec = traverse(root->children_[i]);
            v.insert(v.end(), childVec.begin(), childVec.end());
        }
        v.push_back(root->elements_[i]);
    }
    if(!root->is_leaf_){
        std::vector<int> childVec = traverse(root->children_[root->elements_.size()]);
            v.insert(v.end(), childVec.begin(), childVec.end());
    }
    return v;
}
