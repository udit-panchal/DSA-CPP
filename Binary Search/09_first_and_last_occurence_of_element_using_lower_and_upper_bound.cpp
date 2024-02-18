#include <bits/stdc++.h>
using namespace std;

/*
    Approach 1 : using linear search;
    Time       : O 2*(log n);
    Space      : O(1);
*/

int lower_Bound(vector<int> arr, int target)
{
    int s = 0;
    int e = arr.size() - 1;
    int lb = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] >= target)
        {
            lb = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return lb;
}

int upper_bound(vector<int> &arr, int target)
{
    int s = 0;
    int e = arr.size() - 1;
    int ub = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] <= target)
        {
            ub = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    return ub;
}

pair<int, int> first_and_last_occurence(vector<int> arr, int target)
{
    int first_Occurence = lower_Bound(arr, target);
    int last_Occurence = upper_bound(arr, target);

    if (first_Occurence == -1 || arr[first_Occurence] != target)
        return make_pair(-1, -1);

    return make_pair(first_Occurence, last_Occurence);
}

int main()
{
    vector<int> arr = {2, 4, 5, 6, 8, 8, 8, 11, 13};
    int target = 8;
    pair<int, int> result = first_and_last_occurence(arr, target);

    cout << "Target  = " << target << endl;
    cout << "First Occurence : " << result.first << endl;
    cout << "Last Occurence : " << result.second << endl;

    return 0;
}