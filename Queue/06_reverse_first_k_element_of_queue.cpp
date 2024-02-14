#include <bits/stdc++.h>
using namespace std;

void reverse_first_k_element(queue<int> &q, int k)
{
    stack<int> s;

    // Push the first k elements of the queue onto the stack    
    int count = 0;
    while (count != k)
    {
        s.push(q.front());
        q.pop();
        count++;
    }

    count = 0;
    // Move the remaining elements after the first k elements to the end of the queue
    while (count != k)
    {
        q.push(s.top());
        s.pop();
        count++;
    }

    // Move the remaining elements after the first k elements to the end of the queue
    for (int i = 0; i < q.size() - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    // q.push(6);

    int k = 2;

    reverse_first_k_element(q, k);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}