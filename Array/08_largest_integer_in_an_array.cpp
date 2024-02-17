#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int arr[n] = {3, 2, 1, 5, 2};
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > ans)
        {
            ans = arr[i];
        }
    }

    cout << ans << endl;

    return 0;
}