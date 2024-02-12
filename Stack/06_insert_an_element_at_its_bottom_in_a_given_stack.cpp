#include <bits/stdc++.h>
using namespace std;

void insertBottom(stack<int> &inputStack, int element)
{
    if (!inputStack.empty())
    {
        inputStack.push(element);
        return;
    }

    int temp = inputStack.top();
    inputStack.pop();

    insertBottom(inputStack, element);

    inputStack.push(temp);
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
    stack<int> inputStack;
    inputStack.push(111);
    inputStack.push(222);
    inputStack.push(333);
    inputStack.push(444);
    inputStack.push(555);

    cout << " 1 :-> ";
    print(inputStack);

    insertBottom(inputStack, 999);

    cout << " 2 :-> ";
    print(inputStack);

    return 0;
}