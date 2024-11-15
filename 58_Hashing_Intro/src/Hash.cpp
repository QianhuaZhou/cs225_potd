#include <vector>
#include <string>
#include <map>
#include "Hash.h"

using namespace std;

int hashFunction(string s, int M) {
   // Your Code Here
   //hash function to sum up the ASCII characters of the letters of the string
   int ret = 0;
   for(char& c : s){
	ret += static_cast<int>(c);
   }
   return ret%M;
 }

int countCollisions (int M, vector<string> inputs) {
	int collisions = 0;
	// Your Code Here
	std::vector<int> hashTable(M, 0);
	for(string& s : inputs){
		hashTable[hashFunction(s, M)]++;
	}
	for(int& i : hashTable){
		if(i > 1) collisions += (i-1);
	}

	return collisions;
}
