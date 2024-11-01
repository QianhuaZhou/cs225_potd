#include <iostream>
#include <string>
#include <numeric>

#include "adjacency_matrix.h"

using namespace std;

/*
 Implement the functions below
 */

bool containsEdge(Graph const * const g, int src, int dest) {
    return g->adjMatrix[src][dest];
}

void addEdge(Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = true;
}

int numOutgoingEdges(Graph const * const g, int v) {
    int ret = 0;
    //unsigned int size = sizeof(g->adjMatrix[v])/sizeof(g->adjMatrix[v][0]);//number of columns
    for(int i= 0; i < g->n; ++i){
        ret += g->adjMatrix[v][i];
    }
    return ret;
}


int numIncomingEdges(Graph const * const g, int v) {
    int ret = 0;
    //unsigned int size = sizeof(g->adjMatrix)/sizeof(g->adjMatrix[0][v]);//number of columns
    for(int i= 0; i < g->n; ++i){
        ret += g->adjMatrix[i][v];
    }
    return ret;
}

void printGraph(Graph const * const g) {
        cout << "Adjacency Matrix: " << endl;
        for (int i = 0; i < g->n; i += 1) {
                for (int j = 0; j < g->n; j += 1) {
                        bool neighbor = g->adjMatrix[i][j];
                        cout << neighbor << " ";
                }
                cout << "\n\n";
        }
}

Graph* createVertices(int numV) {
    // No need to modify this function
    Graph* g = new Graph();
    g->n = numV;
    g->adjMatrix = new bool*[numV];
    for (int i = 0; i < numV; i += 1) {
        g->adjMatrix[i] = new bool[numV];
        for (int j = 0; j < numV; j += 1) {
            g->adjMatrix[i][j] = 0;
        }
    }
    return g;
}
