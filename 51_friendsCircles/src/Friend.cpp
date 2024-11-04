#include "Friend.h"
#include <iostream>

int find(int x, std::vector<int>& parents) {
   // your code
    //std::cout << __LINE__ << " parents.size() = " << parents.size() << " " << " x = " << x << std::endl;
    if(parents[x] < 0){
        return x;
    }
    return parents[x] = find(parents[x], parents); ;
}

void unionSets(int x, int y, std::vector<int>& parents){
    int rootX = find(x, parents);
    int rootY = find(y, parents);
    if(rootX != rootY) parents[rootY] = rootX;
}

int findCircleNum(std::vector<std::vector<int>>& M) {
    // your code
    std::vector<int> parents(M[0].size(), -1);
    for(int i = 0; i < static_cast<int>(M.size()); ++i){
        for(int j = i + 1; j < static_cast<int>(parents.size()); ++j){
            if(M[i][j] == 1) unionSets(i, j, parents);
        }
    }
    int count = 0;
    for (int i = 0; i < static_cast<int>(parents.size()); ++i) {
        if (parents[i] < 0) {
            count++;
        }
    }
    return count;

 
    
    
}


