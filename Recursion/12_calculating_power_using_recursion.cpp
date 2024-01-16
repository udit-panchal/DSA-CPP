#include <bits/stdc++.h>
using namespace std;

int calPower(int a, int b)
{
    if (b == 0)
        return 1;

    if (b == 1)
        return a;

    // Recursive call
    int ans = calPower(a, b / 2);

    // if b i even
    if (b % 2 == 0)
        return ans * ans;

    // if b is odd
    else
        return ans * ans * a;
}

int main()
{
    int a = 3, b = 10; //59049
    // int a = 3, b = 11; //177147
    int ans = calPower(a, b);

    cout << ans << endl;

    return 0;
}