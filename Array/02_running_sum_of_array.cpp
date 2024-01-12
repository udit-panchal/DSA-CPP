#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int> nums)
{

    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] = nums[i] + nums[i - 1];
    }

    return nums;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4}; // [1,3,6,10]

    vector<int> output = runningSum(nums);

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i];
    }

    return 0;
}

/*

    leetcode

        - running sum of 1d array
        - https://leetcode.com/problems/running-sum-of-1d-array/

    -----------------------------------------------------------------------------------------------------------------------
    statement

    - Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

    Return the running sum of nums.
    -----------------------------------------------------------------------------------------------------------------------

    Input: nums = [1,2,3,4]
    Output: [1,3,6,10]
    Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

    ---------------------
    Input: nums = [1,1,1,1,1]
    Output: [1,2,3,4,5]
    Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].

    -----------------------------------------------------------------------------------------------------------------------

*/
