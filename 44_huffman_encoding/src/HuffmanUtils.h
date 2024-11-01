#ifndef _HUFFUTILS_H
#define _HUFFUTILS_H

#include <string>
#include <map>

using std::string;

string stringToBinary(string charString, HuffmanNode* huffmanTree);
string binaryToString(string binaryString, HuffmanNode* huffmanTree);
//void stringToBinaryMap(HuffmanNode* curr, std::map<char, string>& m, string bitRecord);

#endif
