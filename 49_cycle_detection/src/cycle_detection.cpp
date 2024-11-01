#include <iostream>
#include <string>
#include <stack>
#include <map>

#include "graph.cpp"

// TODO: Implement this function
bool searchCycle(Node*& node, std::map<int, bool>& visited, std::map<int, bool>& currCycle){
    visited[node->value] = true;
    currCycle[node->value] = true;
    for(unsigned int i = 0; i < node->outgoingNeighbors.size(); i++) {
        Node* curr = node->outgoingNeighbors[i];
        if(!visited[curr->value]){
            if(searchCycle(curr, visited, currCycle)) return true;
        }else if(currCycle[curr->value]){
            return true;//cycle detected
        }
    }
    currCycle[node->value] = false;//remove from recursive stack
    return false;
}

bool hasCycles(Graph const & g) {
    
    int V = g.nodes.size();
    std::map<int, bool> visited;//default value for bool: false
    std::map<int, bool> currCycle;
    //for(Node* n : g.nodes) visited[n->value] = false;//initialize the map
    for(int i = 0; i < V; i++) {
        Node* node = g.nodes[i];
        if(!visited[i]){
            if(searchCycle(node, visited, currCycle)) return true;
        }
    }
    return false;
}
