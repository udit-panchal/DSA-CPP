#include <bits/stdc++.h>
using namespace std;

bool solve(string expression)
{
    stack<char> s;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        if (ch == '{' || ch == '[' || ch == '(')
        {
            s.push(expression[i]);
        }
        else
        {
            if (!s.empty())
            {
                char top = s.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
                return false;
        }
    }

    return s.empty();
}

void print(stack<int> str)
{
    cout << "Elements in the stack are : ";
    while (!str.empty())
    {
        cout << str.top() << " ";
        str.pop();
    }
    cout << endl;
}

int main()
{
    // string expression = "{{[()]}}";          //balanced
    // string expression = "{[()()]()}";        //balanced
    // string expression = "{[(){}()]}";        //balanced
    // string expression = "{[()]}";            //balanced
    string expression = "{[()]}}}";          //unbalanced

    if (solve(expression))
    {
        cout << "Expression is balanced." << endl;
    }
    else
    {
        cout << "Expression is not balanced." << endl;
    }
    return 0;
}