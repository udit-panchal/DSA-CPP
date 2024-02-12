#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &arr, int n)
{
    stack<int> s;

    // push all candidate in stack
    for (int i = 0; i < n; i++)
        s.push(i);

    // find potential candidate
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (arr[a][b] == 1)
            s.push(b);
        else
            s.push(a);
    }

    // top of the stack have potential candidate
    int candidate = s.top();

    // RULES :-
    //  1). everyone knows celebrity
    //  2). celebrity not know anyone
    //  3). arr[celebrity][celebrity] == 0;

    // check for rules
    for (int i = 0; i < n; i++)
    {
        if (i != candidate && (arr[candidate][i] == 1 || arr[i][candidate] == 0))
            return -1;
    }

    // the candidate is the celebrity
    return candidate;
}

int main()
{
    // vector<vector<int>> arr = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    vector<vector<int>> arr = {{0, 0, 1, 0},
                               {0, 0, 1, 0},
                               {0, 0, 0, 0},
                               {0, 0, 1, 0}};
    int n = arr.size();

    int celeb = celebrity(arr, n);

    if (celeb != -1)
        cout << "Celebrity is person " << celeb << endl;
    else
        cout << "No celebrity found" << endl;

    return 0;
}
