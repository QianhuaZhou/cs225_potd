#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

/**
This graph is implemented as an adjacency matrix
*/
struct ResidualNetwork {

    vector<vector<int>> adjacencyMatrix;
    int source;
    int sink;
    int numNodes;

    ResidualNetwork(int n): adjacencyMatrix(n, vector<int>(n, -1)), source(0), sink(n-1), numNodes(n) {};

    // Returns the set of neighbors from the outgoing edges of this node
    vector<int> outgoingNeighbors(int node) {
        std::vector<int> ret;
        for (int i = 0; i < numNodes; i++) {
            /* code */
            int maybeNode = adjacencyMatrix[node][i];
            if (maybeNode >= 0) {
                ret.push_back(i);
            }
        }
        return ret;
    }

    // Sets an edge in the graph with a capacity
    void setEdge(int u, int v, int capacity) {
        adjacencyMatrix[u][v] = capacity;
    }

    // Removes the edge in the graph
    void removeEdge(int u, int v) {
        adjacencyMatrix[u][v] = -1;
    }

    /**
    Returns the capacity of the edge or -1 if edge doesn't exist
    */
    int edgeCapacity(int u, int v) {
        return adjacencyMatrix[u][v];
    }
};

// Prints the graph
void printGraph(ResidualNetwork const & g) {
    std::cout << "Source: " << g.source << '\n';
    std::cout << "Sink: " << g.sink << '\n';

    int n = g.adjacencyMatrix.size();

    for (int i = 0; i < n; i++) {
        std::cout << "Node: " << i << " | (neighbors, capacity):";
        for (int j = 0; j < n; j++) {
            int maybeNode = g.adjacencyMatrix[i][j];
            if (maybeNode >= 0) {
                std::cout << " (" << j << ", " << maybeNode << ")";
            }
        }
        std::cout << '\n';
    }
}

/**
Just some function that checks whether the vector of nodes contains that node
This can be useful if you are doing a graph search function.
Maybe the first parameter represents your visited set? :)
*/
bool contains(vector<int> v, int n){
  for (size_t i = 0; i < v.size(); i++){
    if(v[i] == n){
      return true;
    }
  }
  return false;
}
