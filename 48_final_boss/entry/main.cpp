#include <cstdio>

#include "find_boss.cpp"

int main() {
    // Construct graph
    vector<Node*> nodesVec;
    Node* startingNode = new Node("a", 3);
    Node* bossNode = new Node("d", 5, true);

    nodesVec.push_back(startingNode);
    nodesVec.push_back(new Node("b", 1));
    nodesVec.push_back(new Node("c", 3));
    nodesVec.push_back(bossNode);

    Graph g(nodesVec, startingNode);
    g.addEdge("a", "b");
    g.addEdge("a", "c");
    g.addEdge("b", "d");
    g.addEdge("c", "d");

    // Find that boss!
    bool foundAndDefeated = findBoss(g, bossNode);
    std::cout << "Boss found and defeated: " << boolalpha << foundAndDefeated << std::endl;
}
