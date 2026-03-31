#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

class Expression {
public:
    bool isOperator(char ch);
    int precedence(char op);
    std::string infixToPostfix(const std::string& infix);
    int evaluatePostfix(const std::string& postfix);
};

#endif