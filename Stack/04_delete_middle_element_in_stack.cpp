#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &inputStack, int count, int size)
{
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }

    int temp = inputStack.top();
    inputStack.pop();

    solve(inputStack, count + 1, size);

    inputStack.push(temp);
}

void deleteMiddle(stack<int> &inputStack, int size)
{
    int count = 0;
    solve(inputStack, count, size);
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
    deleteMiddle(inputStack, 5);
    cout << " 2 :-> ";
    print(inputStack);

    return 0;
}