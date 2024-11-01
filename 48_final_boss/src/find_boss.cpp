#include <queue>
#include <map>

#include "graph.cpp"

using namespace std;

typedef map<Node*, bool> clearedMap;

/*
Return true if you have defeated the boss, false if they are unbeatable and the player must give up
NOTE: If you are too weak to defeat the boss, then don't try! You will be defeated and gain 0 Exquisite Chocolate points!

@param map      This graph contains everything you need to traverse over
@param bossNode Here resides the boss you must defeat once you are strong enough
*/
bool findBoss(Graph& map, Node* bossNode) {
    clearedMap cleared;
    queue<Node*> toVisit;
    queue<Node*> tooStrong;
    Node* playerNode;

    // TODO: Follow the comments and finish this function!

    // Add initial neighbors to be visited
    playerNode = map.getPlayerNode();
    for(Node* i : playerNode->neighbors) toVisit.push(i);
    while(!toVisit.empty()) {
        // Check if we can teleport directly to the boss and win
        Node* target = toVisit.front();
        toVisit.pop();
        if(bossNode->getStrength() < playerNode->getStrength()){
            map.movePlayer(playerNode, bossNode);
            if(map.wasBossDefeated()) return true;
        }
        if(target->getTimesVisited() != 0) continue;

        if(target->getStrength() < playerNode->getStrength()){
            map.movePlayer(playerNode, target);
            if(map.wasBossDefeated()) return true;
            playerNode = target;
            for(Node* i : playerNode->neighbors){
                //if(i->getTimesVisited() == 0) toVisit.push(i); good but not necessary
                toVisit.push(i);
            }
        }else{
            tooStrong.push(target);
        }

        size_t size = tooStrong.size();
        for(size_t i = 0; i < size; ++i){
            Node* curr_target = tooStrong.front();
            tooStrong.pop();
            if(curr_target->getStrength() < playerNode->getStrength()){
                toVisit.push(curr_target);
            }else{
                tooStrong.push(curr_target);
            }
        }
    }
    if(bossNode->getStrength() < playerNode->getStrength()){
            map.movePlayer(playerNode, bossNode);
        }
    return map.wasBossDefeated();
}
