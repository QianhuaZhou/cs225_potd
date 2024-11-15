#include <iostream>

using namespace std;

#include "beiju.h"

int main() {

    while (! cin.eof()) {
        string s;
        getline(cin,s);
        cout << beiju(s) << endl;
    }
}


