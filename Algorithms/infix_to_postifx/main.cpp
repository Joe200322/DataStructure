#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;
// Function to return the weight of the operator => (Tested)
int getWeight(char op)
{
    int weight;
    switch (op)
    {
    case '+':
        weight = 1;
        break;
    case '-':
        weight = 1;
        break;
    case '*':
        weight = 2;
        break;
    case '/':
        weight = 2;
        break;
    case '^':
        weight = 3;
        break;
    default:
        weight = 0;
        break;
    }
    return weight;
}
// function to check if the element is operator or not => (Tested)
bool isOperator(char element)
{
    if (element == '+' || element == '-' || element == '*' || element == '/' || element == '^')
        return true;
    return false;
}
// Function to check if the element is Operand (Numbers or letters) => (Tested)
bool isOperand(char element)
{
    if (element >= 'a' && element <= 'z')
        return true;
    else if (element >= 'A' && element <= 'Z')
        return true;
    else if (element >= '0' && element <= '9')
        return true;
    return false;
}
// Function to check if op1 is bigger that op2
bool isBigger(char op1, char op2)
{
    int weight1 = getWeight(op1);
    int weight2 = getWeight(op2);
    return (weight1 >= weight2) ? true : false;
}

// Function to change infix exepression to postfix
string infixToPostfix(string exepression)
{
    Stack<char> OPs;
    string postfix = "";
    for (char c : exepression)
    {
        if (c == ' ')
            continue;
        else if (isOperand(c))
        {
            postfix.push_back(c);
        }
        else if (isOperator(c))
        {
            while (!OPs.isEmpty() && OPs.top() != '(' && isBigger(OPs.top(), c))
            {
                postfix.push_back(OPs.top());
                OPs.pop();
            }
            OPs.push(c);
        }
        else if (c == '(')
        {
            OPs.push(c);
        }
        else if (c == ')')
        {
            while (!OPs.isEmpty() && OPs.top() != '(')
            {
                postfix.push_back(OPs.top());
                OPs.pop();
            }
            OPs.pop();
        }
    }
    while (!OPs.isEmpty())
    {
        postfix.push_back(OPs.top());
        OPs.pop();
    }
    return postfix;
}
int main()
{
    string exp = "10*(2+1+5)/2-1";
    string postfix = infixToPostfix(exp);
    cout << postfix << endl;
}