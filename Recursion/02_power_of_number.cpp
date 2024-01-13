#include <bits/stdc++.h>
using namespace std;

int power(int n)
{
    // Base case
    if (n == 0)
        return 1;

    return 2 * power(n - 1);
}

int main()
{
    int n;
    cout << "enter no. : ";
    cin >> n;

    int ans = power(n);

    cout << ans << endl;

    return 0;
}

/*
    Recursion Tree
    ==============

        power(5)
           |
      return 2 * power(4)
                    |
               return 2 * power(3)
                            |
                       return 2 * power(2)
                                    |
                               return 2 * power(1)
                                            |
                                       return 2 * power(0)
                                                    |
                                               return 1  (base case)

    call stack of recursion
    =======================

    power(5)
2.   |
3.   |-> power(4)
4.   |     |
5.   |     |-> power(3)
6.   |     |     |
7.   |     |     |-> power(2)
8.   |     |     |     |
9.   |     |     |     |-> power(1)
10.  |     |     |     |     |
11.  |     |     |     |     |-> power(0)
12.  |     |     |     |     |     |
13.  |     |     |     |     |     |-> Base case: return 1
14.  |     |     |     |     |
15.  |     |     |     |     |-> return 2 * 1
16.  |     |     |     |
17.  |     |     |     |-> return 2 * 2
18.  |     |     |
19.  |     |     |-> return 2 * 4
20.  |     |
21.  |     |-> return 2 * 8
22.  |
23.  |-> return 2 * 16

*/