#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


vector<string> topThree(string filename) {
    string line;
    ifstream infile (filename);
    vector<string> ret;
    std::map<string, int> dict;
    if (infile.is_open()) {
        while (getline(infile, line)) {
            // do things
            if(dict.find(line) != dict.end()){
                dict[line] ++;
            }else{
                dict[line] = 1;
            }

        }
    }
    std::vector<std::pair<std::string, int>> vec(dict.begin(), dict.end());
    std::sort(vec.begin(), vec.end(), [](std::pair<std::string, int>& a, std::pair<std::string, int>& b){
        return a.second > b.second;
    });
    for(unsigned int i = 0; i < 3; ++i){
        ret.push_back(vec[i].first);
    }

    infile.close();
    return ret;
}

