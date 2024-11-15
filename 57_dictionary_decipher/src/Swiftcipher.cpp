#include <string>
#include <map>
#include <iostream>
#include <fstream>

#include <vector>
#include <algorithm>

#include "Swiftcipher.h"
using namespace std;


/* Swift Cipher: Frequency of words in a file corresponds to its location in the decrypted sentence */
string decipherer(string filename) {
	std::ifstream file(filename);
	if(!file.is_open()) throw std::runtime_error("Unable to open the file.");
	string s;
	std::map<string, int> map;
	while(file >> s){
		if(map[s] == 0){
			map[s] = 1;
		}else{
			map[s]++;
		}
	}
	std::vector<std::pair<string, int>> vec(map.begin(), map.end());
	std::sort(vec.begin(), vec.end(), [](const std::pair<string, int>& a, const std::pair<string, int>& b){
		return a.second < b.second;
	});
	string ret;
	for(std::pair<string, int>& pair : vec){
		if(pair.first != vec[0].first) ret += " ";
		ret += pair.first;
	}
	return ret;
}
