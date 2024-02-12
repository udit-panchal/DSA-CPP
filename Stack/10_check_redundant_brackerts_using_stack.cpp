#include <bits/stdc++.h>
using namespace std;

bool check_Redudant_Brackets(string expression)
{
    stack<char> st;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isRedundant = true;

                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if (isRedundant)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    // string expression = "(a+b)"; // not redundant
    // string expression = "(((a+b)+c)+d)"; // not redundant

    string expression = "(a+b))";


    if (check_Redudant_Brackets(expression))
    {
        cout << "Expression is redundant." << endl;
    }
    else
    {
        cout << "Expression is not redundant." << endl;
    }
    return 0;
}