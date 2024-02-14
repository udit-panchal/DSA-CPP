#include <bits/stdc++.h>
using namespace std;

string first_non_repeating_char_int_stream(string str)
{
    int n = str.size();

    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";

    for (int i = 0; i < n; i++)
    {
        char ch = str[i];

        count[ch]++;

        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
            ans.push_back('#');
    }

    return ans;
}

int main()
{
    string stream = "aabc";

    string result = first_non_repeating_char_int_stream(stream);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] ;
    }
}