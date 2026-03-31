#include <iostream>
#include "Expression.h"

using namespace std;



int main() {
    Expression exp;
    string infix;

    cout << "Enter fully parenthesized infix expression: ";
    cin >> infix;

    string postfix = exp.infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = exp.evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}