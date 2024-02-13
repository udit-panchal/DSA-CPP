#include <bits/stdc++.h>
using namespace std;

void reverse_a_queue(queue<int> &q)
{
    stack<int> s;

    // Push element in stack from queue and pop from queue
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    // pop element from stack and push into queue
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    queue<int> q;

    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    cout << "front : " << q.front() << endl;

    reverse_a_queue(q);

    cout << "front : " << q.front() << endl;

    return 0;
}