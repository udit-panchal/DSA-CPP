#include <bits/stdc++.h>
using namespace std;

vector<int> smaller_element_in_left(vector<int> &heights, int size)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(size, -1);

    for (int i = 0; i < size; i++)
    {
        while (s.top() != -1 && heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> smaller_element_in_right(vector<int> &heights, int size)
{
    stack<int> s;
    s.push(size);
    vector<int> ans(size, size);

    for (int i = size - 1; i >= 0; i--)
    {
        while (s.top() != size && heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int find_largest_histogram(vector<int> arr)
{
    int n = arr.size();

    vector<int> left = smaller_element_in_left(arr, n);
    vector<int> right = smaller_element_in_right(arr, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int height = arr[i];
        int width = right[i] - left[i] - 1;
        area = max(area, height * width);
    }
    return area;
}

int max_rectangle(vector<vector<int>> arr, int n)
{
    vector<int> histogram(n, 0);

    int max_area = 0;

    for (int i = 0; i < arr[0].size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] == 0)
                histogram[j] = 0;
            else
                histogram[j] += 1;
        }
    
        cout<<max_area<<endl;
        max_area = max(max_area, find_largest_histogram(histogram));
    }

    return max_area;
}

int main()
{
    // vector<vector<int>> arr = {{0, 1, 1, 0},
    //                            {1, 1, 1, 1},
    //                            {1, 1, 1, 1},
    //                            {1, 1, 0, 0}};

    vector<vector<int>> arr = {{1, 1, 1, 0},
                               {1, 1, 1, 1},
                               {1, 1, 1, 1},
                               {1, 1, 1, 0}};

    int n = arr.size();
    int result = max_rectangle(arr, n);

    cout << "max rectangle in matrix is : " << result << endl;

    return 0;
}
