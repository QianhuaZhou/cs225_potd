#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    std::vector<Node*> neighbors;
    string value;

    int getStrength() {
        return strength;
    }

    /** ------------------------------------------------------------------------------------------------- */
    /** Helpers - you do not need to use the following Node functions, unless you wish to make more tests */
    Node(string v, int s): value(v), strength(s), isBoss(false), timesVisited(0) {};
    Node(string v, int s, bool b): value(v), strength(s), isBoss(b), timesVisited(0) {};

    bool hasBoss() {
        return isBoss;
    }

    int getTimesVisited() {
        return timesVisited;
    }

    bool operator==(Node const & other) const {
        return value == other.value && neighbors == other.neighbors;
    }

    /** Returns whether the attack succeeded */
    bool playerAttackingFrom(Node* attackingNode) {
        if(this->strength < attackingNode->getStrength()) {
            this->strength += attackingNode->getStrength();
            attackingNode->clearNode();
            timesVisited++;
            return true;
        } else {
            return false;
        }
    }

    private:
        int strength;
        bool isBoss;
        int timesVisited;

    /** Empty out previous node's strength when you leave it for a new node */
    void clearNode() {
        strength = 0;
    }
    /** ------------------------------------------------------------------------------------------------- */
};

struct Graph {
    Node* getPlayerNode() {
        return playerNode;
    }

    /** If the playerNode is the current player, then it will attempt to teleport to the new node and beat the enemy */
    void movePlayer(Node* sourceNode, Node* destNode) {
        if(sourceNode != playerNode) {
            // Attempted invalid move
            return;
        }

        if(destNode->playerAttackingFrom(sourceNode)) {
            playerNode = destNode;

            if(destNode->hasBoss()) {
                bossDefeated = true;
            }
        } else {
            playerLost = true;
        }
    }

    /** ------------------------------------------------------------------------------------------------- */
    /** Helpers - You do not need to use the following methods, unless you wish to build additional tests */
    Graph(vector<Node*> nodesVec, Node* playerStartNode) : bossDefeated(false), playerLost(false) {
        nodes = nodesVec;
        playerNode = playerStartNode;
    };

    ~Graph() {
        for (size_t i = 0; i < nodes.size(); i++) {
            free(nodes[i]);
        }
    }

    void addEdge(string src, string dst) {
        if (containsEdge(src, dst)) {
            return;
        }

        Node* srcNode = findNode(src);
        Node* dstNode = findNode(dst);
        srcNode->neighbors.push_back(dstNode);
        dstNode->neighbors.push_back(srcNode);
    }

    bool containsEdge(string src, string dst) {
        Node* srcNode = findNode(src);
        Node* dstNode = findNode(dst);
        for (auto neighborIter = srcNode->neighbors.begin(); neighborIter != srcNode->neighbors.end(); neighborIter++) {
            Node* neighbor = *neighborIter;
            if (*neighbor == *dstNode) {
                return true;
            }
        }
        return false;
    }

    bool wasBossDefeated() {
      return bossDefeated;
    }

    bool didPlayerLose() {
      return playerLost;
    }

    bool didntRevisit() {
      for(Node* node : nodes) {
        if(node->getTimesVisited() > 1) {
          return false;
        }
      }

      return true;
    }

    private:
        vector<Node*> nodes;
        Node* playerNode;
        bool bossDefeated;
        bool playerLost;

        Node* findNode(string nodeVal) {
            for(Node* node : nodes){
                if(node->value == nodeVal) {
                    return node;
                }
            }
            // Invalid node name given
            return NULL;
        }
};

bool contains(std::vector<Node*> v, Node* n){
  for (size_t i = 0; i < v.size(); i++){
    if(*v[i] == *n){
      return true;
    }
  }
  return false;
}
