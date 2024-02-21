#include <bits/stdc++.h>
using namespace std;

/*
    Approach 1 : using linear search;
    Time       : O (log n);
    Space      : O(1);
*/

pair<int, int> first_and_last_occurence(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;

    int first_Occurence = -1;
    int last_Occurence = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            first_Occurence = mid;
            end = mid - 1;
        }

        if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    if (first_Occurence == -1 && arr[first_Occurence] != target)
        return make_pair(-1, -1);

    start = 0;
    end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            last_Occurence = mid;
            start = mid + 1;
        }

        if (arr[mid] <= target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return make_pair(first_Occurence, last_Occurence);
}

int main()
{
    // vector<int> arr = {2, 4, 5, 6, 8, 8, 8, 11, 13};
    vector<int> arr = {2, 8, 8, 8, 8, 11, 13};
    int target = 8;
    pair<int, int> result = first_and_last_occurence(arr, target);

    cout << "Target  = " << target << endl;
    cout << "First Occurence : " << result.first << endl;
    cout << "Last Occurence : " << result.second << endl;

    return 0;
}