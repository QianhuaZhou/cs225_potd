#include "HuffmanNode.h"
#include "HuffmanUtils.h"
#include <map>
#include <string>
using std::string;

/**
 * binaryToString
 *
 * Write a function that takes in the root to a huffman tree
 * and a binary string.
 *
 * Remember 0s in the string mean left and 1s mean right.
 */

string binaryToString(string binaryString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    string ret;
    HuffmanNode* curr = huffmanTree;
    if(curr == nullptr) return "";
    for(char& bit : binaryString){
        if(bit == '0'){//go left
            curr = curr->left_;
        }else{//go right
            curr = curr->right_;
        }
        if(curr->left_ == nullptr && curr->right_ == nullptr){//order matters, first put if at the beginning of the for loop, which is incorrect
            ret += curr->char_;
            curr = huffmanTree;
        }
    }
    return ret;
}

void stringToBinaryMap(HuffmanNode* curr, std::map<char, string>& m, string bitRecord){
    if(curr == nullptr) return;
    if(curr->left_ == nullptr && curr->right_ == nullptr){
        m.insert({curr->char_, bitRecord});
        //bitRecord = "";--not desirable, will reset it for all subsequent recursive calls
        return;
    }
    stringToBinaryMap(curr->left_, m, bitRecord + "0");
    stringToBinaryMap(curr->right_, m, bitRecord + "1");
}

/**
 * stringToBinary
 *
 * Write a function that takes in the root to a huffman tree
 * and a character string. Return the binary representation of the string
 * using the huffman tree.
 *
 * Remember 0s in the binary string mean left and 1s mean right
 */
string stringToBinary(string charString, HuffmanNode* curr) {
    /* TODO: Your code here */
    if(curr == nullptr) return "";
    string ret;
    std::map<char, string> map;
    string temp_string = "";
    stringToBinaryMap(curr, map, temp_string);
    for(char& s : charString){
        ret += map[s];
    }
    return ret;
}
