#include "beiju.h"
#include <iostream>
#include <deque>

string beiju(string input) {
    //queue<char> front;
    //queue<char> normal;
    //deque<char> front;
    string front;
    string normal;
    bool at_front = false;
    for(char i : input){
        if(i == '[' || i == ']'){
            at_front = (i == '[') ? true : false;
            normal = front + normal;
            front = "";
        }else{
            if(at_front){
                front += i;
            }else{
                normal  += i;
            }
        }
    }

    return front+normal;
}
