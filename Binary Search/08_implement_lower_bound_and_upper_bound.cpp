#include <bits/stdc++.h>
using namespace std;

pair<int, int> Lower_Bound_And_Upper_Bound(vector<int> arr, int key)
{
    int lower_bound = -1;
    int upper_bound = -1;

    int start = 0;
    int end = arr.size() - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {

        if (arr[mid] >= key)
        {
            lower_bound = mid;
            end = mid - 1;
        }
        else
        {
            upper_bound = mid;
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }

    return make_pair(lower_bound, upper_bound);
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 12, 18};

    pair<int, int> ans = Lower_Bound_And_Upper_Bound(arr, 19);
    cout << "Upper Bound on index : " << ans.first << " : " << arr[ans.first] << endl;
    cout << "Lower Bound on index : " << ans.second << " : " << arr[ans.second] << endl;
}