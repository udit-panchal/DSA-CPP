#include <bits/stdc++.h>
using namespace std;

int numJewelsAndStones_Optimized(string jewels, string stones)
{
    /*
        Time  : O(n)
        Space : O(m);
    */

    unordered_map<char, int> mapping;

    for (int i = 0; i < jewels.length(); i++)
    {
        mapping[jewels[i]];
    }

    int count = 0;
    for (int i = 0; i < stones.length(); i++)
    {
        if (mapping.find(stones[i]) != mapping.end())
            count += 1;
    }

    return count;
}

int numJewelsAndStones(string jewels, string stones)
{

    /*
        Time  : O(n^2)
        Space : O(1);
    */

    int count = 0;
    for (int i = 0; i < jewels.length(); i++)
    {
        for (int j = 0; j < stones.length(); j++)
        {
            if (jewels[i] == stones[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    string A = "aA";
    string B = "aAAbbbb";

    // string A = "z";
    // string B = "ZZ";

    // int result = numJewelsAndStones(A, B);
    int result = numJewelsAndStones_Optimized(A, B);

    cout << result << " ";

    return 0;
}