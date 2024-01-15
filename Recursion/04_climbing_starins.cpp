#include <bits/stdc++.h>
using namespace std;

int climbStairs(int nStairs)
{

    // Base Case
    // when there is no stairs or stairs in -ve.

    if (nStairs < 0)
        return 0;

    // if we are on stair 0
    if (nStairs == 0)
        return 1;

    // Recursive solution
    // there is a rule where climb 1 stairs or 2 stairs at a time
    return climbStairs(nStairs - 1) + climbStairs(nStairs - 2);
}

int main()
{
    int n;
    cout << "enter No : ";
    cin >> n;

    cout << climbStairs(n);

    return 0;
}

/*
    Question ( CodeStudio )
            - Count Ways To Reach The N-th Stairs
            - https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650

-----------------------------------------------------------------------------

    input : 2
    output : 2 (there are only two ways to climb the stairs, i.e. {1,1} and {2}.
)

- - - - - - - - - -

    input : 5
    output : 8 ( there are eight ways to climb the stairs i.e. {1,1,1,1,1} , {1,1,1,2} , {1,1,2,1}, {1,2,1,1}, {2,1,1},{2,2,1},{2,1,2} and {2,2,1}.)


-----------------------------------------------------------------------------

-----------------------------------------------------------------------------





*/