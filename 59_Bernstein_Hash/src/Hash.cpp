#include "Hash.h"
#include <string>
#include <algorithm>
#include <iostream>

unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	//Your code here
	for(char& c : str){
		b_hash = b_hash * 33 + static_cast<int>(c);
	}
	return b_hash % M;
}

std::string reverse(std::string str)
{
    std::string output = str;
	//Your code here
	std::reverse(output.begin(), output.end());
	return output;
}
