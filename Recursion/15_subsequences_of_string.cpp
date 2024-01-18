#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> str, string output, int index, vector<string> &ans)
{
    if (index >= str.size())
    {
        if (!output.empty())
            ans.push_back(output);
        return;
    }

    //exclude current element
    solve(str, output, index + 1, ans);

    // include current element
    output += str[index];
    solve(str, output, index+1, ans);
}

vector<string> subsequencesOfString(vector<string> str)
{
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}

int main()
{
    vector<string> str = {"a", "b", "c"};

    vector<string> ans = subsequencesOfString(str);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}