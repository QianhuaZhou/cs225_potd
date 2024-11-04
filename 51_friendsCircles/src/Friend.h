#ifndef _FRIEND_H
#define _FRIEND_H

#include <vector>

int find(int x, std::vector<int>& parents);

int findCircleNum(std::vector<std::vector<int>>& M);

void unionSets(int x, int y, std::vector<int>& parents);

#endif
