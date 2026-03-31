#include <stack>
#include <cmath>
#include "Expression.h"

using namespace std;

bool Expression::isOperator(char ch)
{
    if (ch == '+') return true;
    if (ch == '-') return true;
    if (ch == '*') return true;
    if (ch == '/') return true;
    if (ch == '^') return true;
    return false;
}

int Expression::precedence(char op)
{
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string Expression::infixToPostfix(const string& infix)
{
    stack<char> s;
    string postfix;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (ch != ' ')
        {
            if (ch >= '0' && ch <= '9')
            {
                postfix = postfix + ch;
            }
            else
            {
                if (ch == '(')
                {
                    s.push(ch);
                }
                else
                {
                    if (ch == ')')
                    {
                        while (!s.empty() && s.top() != '(')//top is not '(' and also not  empty stack
                        {
                            postfix = postfix + s.top();
                            s.pop();
                        }

                        if (!s.empty())
                        {
                            s.pop(); //pop the '(' from stack
                        }
                    }
                    else
                    {
                        if (isOperator(ch))
                        {
                            while (!s.empty() && precedence(s.top()) >= precedence(ch))
                            {
                                postfix = postfix + s.top();
                                s.pop();
                            }
                            s.push(ch);
                        }
                    }
                }
            }
        }
    }

    while (!s.empty())
    {
        postfix = postfix + s.top();
        s.pop();
    }

    return postfix;
}

int Expression::evaluatePostfix(const string& postfix)
{
    stack<int> s;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        if (ch >= '0' && ch <= '9')
        {
            s.push(ch - '0');
        }
        else
        {
            if (isOperator(ch))
            {
                int operand2 = s.top();
                s.pop();
                int operand1 = s.top();
                s.pop();

                int result = 0;

                if (ch == '+') result = operand1 + operand2;
                if (ch == '-') result = operand1 - operand2;
                if (ch == '*') result = operand1 * operand2;
                if (ch == '/') result = operand1 / operand2;
                if (ch == '^') result = pow(operand1, operand2);

                s.push(result);
            }
        }
    }

    return s.top();
}