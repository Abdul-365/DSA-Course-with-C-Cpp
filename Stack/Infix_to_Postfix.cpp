#include <iostream>
#include <conio.h>
#include <stack>
using namespace std;

int precedence(string operator_)
{
    if (operator_[0] == '^')
        return 3;
    else if (operator_[0] == '/' || operator_[0] == '*')
        return 2;
    else if (operator_[0] == '+' || operator_[0] == '-')
        return 1;
    else
        return -1;
}

int main()
{
    system("cls");
    string infix, postfix;
    stack<string> stack;

    cout << "Enter infix expression: ";
    getline(cin, infix);
    stack.push("(");
    infix.append(")");
    for (int i = 0; i < infix.length(); i++)
    {
        string element(1, infix[i]);
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
            postfix.append(element);
        else if (infix[i] == '(')
            stack.push("(");
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            if (precedence(stack.top()) >= precedence(element))
            {
                while (stack.top() != "(")
                {
                    postfix.append(stack.top());
                    stack.pop();
                }
            }
            stack.push(element);
        }
        else if (infix[i] == ')')
        {
            while (stack.top() != "(")
            {
                postfix.append(stack.top());
                stack.pop();
            }
            stack.pop(); // Pop left parenthesis
        }
    }
    cout << "\nPostfix expression: " << postfix;
    return 0;
}