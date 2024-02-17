#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();

    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = nums[i];
    }

    nums = temp;
}

void print(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int mod (int a, int b)
{
    return a%b;
}


int main()
{

    // vector<int> nums = {1,2,3,4,5,6,7}; // {5,6,7,1,2,3,4}
    // int k = 3;

    vector<int> nums = {11,12,13,14,15}; // {13,14,15,11,12}
    int k = 3;

    // vector<int> nums = {-1,-100,3,99}; // {3,99,-1,-100}
    // int k = 2;

    cout<<"before rotate : ";
    print(nums);

    rotate(nums, k);

    cout<<"after rotate  : ";
    print(nums);



    return 0;
    
}