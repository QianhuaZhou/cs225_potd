#include "Pattern.h"
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <unordered_set>

bool wordPattern(std::string pattern, std::string str) {
    //write your code here
    std::istringstream stream(str);
    std::string word;
    std::map<char, std::string> mapping;
    std::unordered_set<std::string> usedWords;//bijection
    int count = 0;
    while(stream >> word){
        if(count >= static_cast<int>(pattern.size())) return false;
        char curr = pattern.at(count);
        if(mapping.find(curr) == mapping.end()){
            if (usedWords.find(word) != usedWords.end()) {
                return false;  // The word is already mapped to another character
            }
            mapping[curr] = word;
            usedWords.insert(word);
        }else if(word != mapping[curr]){
           return false;
        }
        count += 1;
    }
    return count == static_cast<int>(pattern.size());
}

