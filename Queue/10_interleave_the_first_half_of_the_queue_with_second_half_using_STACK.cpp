#include <bits/stdc++.h>
using namespace std;

void interleave_two_half_of_queue(queue<int> &q, int n)
{
    stack<int> st;
    int mid = n / 2;

    for (int i = 0; i < mid; i++)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    for (int i = 0; i < mid; i++)
    {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < mid; i++)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{

    queue<int> q;

    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    int n = q.size();
    interleave_two_half_of_queue(q, n);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

/*
    # Interleave the first half of the queue with second half using STACK

    Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

    Input :  1 2 3 4
    Output : 1 3 2 4

    Input : 11 12 13 14 15 16 17 18 19 20
    Output : 11 16 12 17 13 18 14 19 15 20
*/