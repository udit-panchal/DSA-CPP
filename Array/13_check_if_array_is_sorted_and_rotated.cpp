#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& nums)
{
    for(int i = 0; i<nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }cout<<endl;
}

bool checkSortedRotated(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;

    for(int i = 1; i<nums.size(); i++)
    {
        if(nums[i-1] > nums[i] )
        {
            count++;
        }
    }

    if(nums[0] < nums[n-1])
    {
        count++;
    }

    return count <= 1;

}


int main() 
{
    vector<int> nums = {3,4,5,1,2};

    cout<<checkSortedRotated(nums)<<endl;


    return 0;
}



