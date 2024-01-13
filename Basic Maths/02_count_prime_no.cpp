#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

int countPrime(int n)
{
    int count = 0;

    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
            count++;
    }

    return count;
}

int main()
{
    int n;
    cout<<"enter no : ";
    cin >> n;

    cout << "total prime present between 1 to " << n << " : " << countPrime(n);
}