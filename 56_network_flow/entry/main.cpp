#include <cstdio>
#include <vector>
#include <iostream>

#include "augmenting_path.cpp"

using namespace std;

int main() {
    ResidualNetwork g = ResidualNetwork(3);
    g.setEdge(0, 1, 0);
    g.setEdge(1, 2, 1);
    printGraph(g);

    bool augmentingPath = hasAugmentingPath(g);
    cout << "Has augmenting path: " << augmentingPath << endl;

    ResidualNetwork g2 = ResidualNetwork(3);
    g2.setEdge(0, 1, 1);
    g2.setEdge(1, 2, 1);

    printGraph(g2);

    bool augmentingPath2 = hasAugmentingPath(g2);
    cout << "Has augmenting path: " << augmentingPath2 << endl;

}
