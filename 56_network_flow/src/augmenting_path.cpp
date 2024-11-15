#include "network_flow.cpp"
#include <queue>
#include <map>

// TODO: Implement this function. Try using BFS/DFS
bool hasAugmentingPath(ResidualNetwork r) {
    std::queue<int> queue;//BFS
    vector<int> neighbors = r.outgoingNeighbors(r.source);
    queue.push(r.source);
    int curr;
    while(!queue.empty()){
        curr = queue.front();
        queue.pop();
        for(int& i : r.outgoingNeighbors(curr)){
            if(r.edgeCapacity(curr, i)){
                if(i == r.sink)return true;
                queue.push(i);
            }
        }
    }

    return false;
}
