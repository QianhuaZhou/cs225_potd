#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Hash.h"

unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	for (int i = 0; i < (int) str.length(); ++i)
	{
		b_hash = b_hash * 33 + str[i];
	}
	return b_hash % M;
}

float hash_goodness(std::string str, int M)
{
    std::vector<int> array;	// Hint: This comes in handy
	int permutation_count = 0;	
	float goodness = 0;
	float collisions = 0;
	do {
		if (permutation_count == M) break;
		// Code for computing the hash and updating the array
		int temp = bernstein(str, M);
		for(unsigned long i = 0; i < array.size(); i++){
			if(array.at(i) == temp){
				collisions++;
				break;
			}
		}
		array.push_back(bernstein(str, M));
		permutation_count++;
	} while(std::next_permutation(str.begin(), str.end()));
	//Code for determining goodness
	goodness = collisions / M;
	return goodness;
}

