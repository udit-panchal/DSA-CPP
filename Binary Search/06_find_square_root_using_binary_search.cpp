#include <iostream>
using namespace std;

int findSqrRoot(int num)
{
    int s = 0;
    int e = num;
    int mid = (s + e) / 2;

    int ans = -1;
    while (s <= e)
    {
        int square = mid * mid;

        if (num == square)

        {
            return mid;
        }
        
        if (square <= num)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (square >= num)
        {
            e = mid - 1;
        }

        mid = (s + e) / 2;
    }
    return ans;
}

int main()
{

    int num = 36;

    int ans = findSqrRoot(num);

    cout << "square root of " << num << " is : " << ans;
}