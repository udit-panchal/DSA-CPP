#include <bits/stdc++.h>
using namespace std;

void reverse(string &str)
{

    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        s.push(ch);
    }

    for (int i = 0; i < str.length(); i++)
    {
        str[i] = s.top();
        s.pop();
    }
}

void print(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i];
    }
    cout << endl;
}

int main()
{
    string str = "udit";

    cout << "Before reverse : ";
    print(str);

    reverse(str);
    
    cout << "After reverse  : ";
    print(str);
}
