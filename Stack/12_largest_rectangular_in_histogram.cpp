#include <bits/stdc++.h>
using namespace std;

vector<int> smaller_element_in_right(vector<int> &heights, int size)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(size, -1);

    for (int i = size - 1; i >= 0; i--)
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

int largest_histogram(vector<int> &heights)
{
    int n = heights.size();

    vector<int> left = smaller_element_in_left(heights, n);

    vector<int> right = smaller_element_in_right(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int height = heights[i];
        int width = right[i] - left[i] -1;
        area = max(area, height * width);
    }
    return area;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int ans = largest_histogram(heights);

    cout << "largest rectangle in histogram : " << ans << endl;

    return 0;
}