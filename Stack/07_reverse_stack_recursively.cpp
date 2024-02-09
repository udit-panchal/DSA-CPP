#include <bits/stdc++.h>
using namespace std;

void insertBottom(stack<int> &inputStack, int element)
{
    if (inputStack.empty())
    {
        inputStack.push(element);
        return;
    }

    int temp = inputStack.top();
    inputStack.pop();

    insertBottom(inputStack, element);

    inputStack.push(temp);
}

void reverse(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();

    reverse(stack);
    insertBottom(stack, num);
}

void print(stack<int> str)
{
    if (str.empty())
    {
        return;
    }

    int num = str.top();
    str.pop();

    cout << num << " ";
    print(str);

    str.push(num);
}

int main()
{
    stack<int> stack;
    stack.push(111);
    stack.push(222);
    stack.push(333);
    stack.push(444);
    stack.push(555);

    cout << " 1 :-> ";
    print(stack);
    cout << endl;
    reverse(stack);

    cout << " 2 :-> ";
    print(stack);

    return 0;
}