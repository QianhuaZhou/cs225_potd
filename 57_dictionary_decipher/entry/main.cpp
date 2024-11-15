#include <iostream>
#include <vector>
#include "Swiftcipher.h"

int main() {
    // call decipherer here!
    std::string s = decipherer("../tests/example.txt");
    std::cout << s << std::endl;
	return 0;	
}
