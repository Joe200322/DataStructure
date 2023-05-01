#include <iostream>
#include "../../DataStructure/Stack/Stack.h"
#include <string>
using namespace std;

int longestValidParentheses(string parentheses){
    int numOfPArentheses = 0;
    Stack <char> paren;
for (int i = 0 ;i < parentheses.size();i++) {
    if (parentheses.at(i) != '(' && parentheses.at(i) != ')') {
        cout << "wrong input" << endl;
        break;
    } else {

        paren.push(parentheses.at(i));

    }
}
    for (int i =0 ; i < paren.size();i++){
        if (paren.top() != paren.top()-1){
            numOfPArentheses +=2;
            paren.pop();
            paren.pop();

        }
        else{
            paren.pop();
        }
    }

    return numOfPArentheses;
}

int main() {
    cout << longestValidParentheses(")()())");


}
