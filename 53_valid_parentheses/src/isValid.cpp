#include <string>
#include <stack>

using namespace std;

bool isValid(string input) {
    stack<char> st;
    for(char i : input){
        if(i == '(' || i == '[' || i == '{'){
            st.push(i);
        }else if(i == ')' || i == ']' || i == '}'){
            if(st.empty()) return false;
            char top = st.top();
            if(!((i == ')' && top == '(') || (i == ']' && top == '[') || (i == '}' && top == '{'))){
                return false;
            }
            st.pop();
        }
    }
    return st.empty();    // modify this!
}