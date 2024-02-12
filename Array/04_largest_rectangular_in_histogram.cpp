#include <bits/stdc++.h>
using namespace std;

int largest_histogram(int arr[], int size)
{
    int maxArea = 0;
    for (int i = 0; i < size; i++)
    {
        int left = i;
        int right = i;

        while ((left > 0) && (arr[left - 1] >= arr[i]))
            left--;

        while ((right < size - 1) && (arr[right + 1] >= arr[i]))
            right++;

        int area = arr[i] * (right - left + 1);
        cout << "(i)" << arr[left] << ":"
             << "(j)" << arr[right] << " = " << area << endl;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main()
{
    int arr[6] = {2, 1, 5, 6, 2, 3};
    int size = 6;

    int result = largest_histogram(arr, size);

    cout << "The largest histogram possible is : " << result << endl;

    return 0;
}

// optimized approach is in stack folder"