#include <bits/stdc++.h>
using namespace std;



/*
    Approach 1 : using linear search;
    Time       : O(N);
    Space      : O(1);
*/
pair<int, int> first_and_last_occurence(vector<int> arr, int target)
{
    int first = -1;
    int last = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            if (first == -1)
            {
                first = i;
            }
            last = i;
        }
    }

    return make_pair(first, last);
}

int main()
{
    vector<int> arr = {2, 4, 5, 6, 8, 8, 8, 11, 13};
    int target = 8;
    pair<int, int> result = first_and_last_occurence(arr, target);

    cout << "Target  = " << target << endl;
    cout << "First Occurence : " << result.first << endl;
    cout << "Secound Occurence : " << result.second << endl;

    return 0;
}