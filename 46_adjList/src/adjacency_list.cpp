#include <iostream>
#include <string>
#include "adjacency_list.h"

using namespace std;

bool containsEdge(Graph const * const g, int src, int dest) {
        // Your code here
        AdjacencyList* list = g->adjLists;
        std::cout << __LINE__ << " src = " << src << "; dest = " << dest << ";  g->n = " << g->n << std::endl;
        if(src >= g->n) return false;
        LinkedListNode* node = list[src].edges;
        while(node != nullptr){
                std::cout << __LINE__ << " node->v = " << node->v << std::endl;
                if(node->v == dest) return true;
                node = node->next;
        }
        return false;
}

void addEdge(Graph* g, int src, int dest) {
        // Your code here
        AdjacencyList* list = g->adjLists;;
        LinkedListNode* node = list[src].edges;
        //std::cout << __LINE__ << " list[src].edges = " << list[src].edges << std::endl;
        if(node != nullptr){
                std::cout << __LINE__ << "node is not empty" << std::endl;
                while(node->next != nullptr){
                        std::cout << __LINE__ << " node->v = " << node->v << std::endl;
                        if(node->v == dest) return;
                        node = node->next;
                }
                if(node->v == dest) return;
                LinkedListNode* newNode = new LinkedListNode();
                newNode->v = dest;
                newNode->next = nullptr;
                node->next = newNode;
                
        }else{
                //node = new LinkedListNode();
                /*list[src].edges is nullptr (i.e., there are no edges for src yet), assigning node = new LinkedListNode();
                 will only modify the local node pointer, not the actual edges pointer in list[src]. 
                 In other words, node is just a copy of the pointer, 
                so changes to node itself won't affect list[src].edges.*/
                LinkedListNode* newNode = new LinkedListNode;
                newNode->v = dest;
                newNode->next = nullptr;
                list[src].edges = newNode;
        }
        
        

}

int numOutgoingEdges(Graph const * const g, int v) {
        // Your code here
        AdjacencyList* list = g->adjLists;
        LinkedListNode* node = list[v].edges;
        int count = 0;
        while(node != nullptr){
                count ++;
                node = node->next;
        }
        return count;
}


int numIncomingEdges(Graph const * const g, int v) {
        // Your code here
        AdjacencyList* list = g->adjLists;
        int count = 0;
        for(int i = 0; i < g->n; ++i){
                LinkedListNode* node = list[i].edges;
                while(node != nullptr){
                        if(node->v == v) count ++;
                        node = node->next;
                }
                
        }
        return count;
}

// No need to modify the functions below

Graph* createVertices(int numV) {
        Graph* g = new Graph();
        g->adjLists = new AdjacencyList[numV];
        g->n = numV;

        // Initialize the vertices
        for (int i = 0; i < numV; i += 1) {
                g->adjLists[i].vertex = i;
                g->adjLists[i].edges = NULL;
        }

        return g;
}

void printGraph(Graph const * const g) {
    for (int i = 0; i < g->n; i += 1) {
        AdjacencyList adjList = g->adjLists[i];

        int v = adjList.vertex;
        // Vertex
        cout << "Vertex: " << v << endl;
        // Print number of incoming and outgoing edges
        int inc = numIncomingEdges(g, v);
        int out = numOutgoingEdges(g, v);
        cout << "Number of incoming edges: " << inc << endl;
        cout << "Number of outgoing edges: " << out << endl;

        cout << "\n" << endl;
    }
}
