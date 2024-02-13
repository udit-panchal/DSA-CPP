#include <bits/stdc++.h>
using namespace std;

vector<int> first_negative_in_k_size_window(vector<int> arr, int k)
{
    int n = arr.size(); // Size of the input array

    deque<int> windowIndex; // Deque to store the index of elements in the current window
    vector<int> result;     // Vector to store the first negative element in each window

    // Process the first window of size k
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
            windowIndex.push_back(i); // Add index to deque if element is negative
    }

    // Add the first negative element in the initial window to the result vector
    if (windowIndex.size() > 0)
    {
        result.push_back(arr[windowIndex.front()])
    }
    else
    {
        result.push_back(0)
    };

    // Process the remaining windows
    for (int i = k; i < n; i++)
    {
        // Remove elements from the front of the deque if they are outside the current window
        if (!windowIndex.empty() && i - windowIndex.front() >= k)
            windowIndex.pop_front();

        // If the current element is negative, add its index to the deque
        if (arr[i] < 0)
            windowIndex.push_back(i);

        // Add the first negative element in the current window to the result vector
        result.push_back(windowIndex.size() > 0 ? arr[windowIndex.front()] : 0);
    }

    return result; // Return the result vector
}

int main()
{
    vector<int> arr = {-8, 2, 3, -6, 10};

    // int windowSize = 3;
    int windowSize = 2;
    vector<int> ans = first_negative_in_k_size_window(arr, windowSize);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}