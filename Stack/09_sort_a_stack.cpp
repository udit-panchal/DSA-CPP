#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &stack, int num)
{
    if (stack.empty() || (!stack.empty() && stack.top()<num))
    {
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();
    sortedInsert(stack,num);

    stack.push(n);

}

void sort(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();
    sort(stack);

    sortedInsert(stack, num);
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
    stack.push(11231);
    stack.push(333);
    stack.push(999);
    stack.push(8999);
    stack.push(555);

    cout << " Before :-> ";
    print(stack);
    cout << endl;
    sort(stack);

    cout << " After  :-> ";
    print(stack);

    return 0;
}