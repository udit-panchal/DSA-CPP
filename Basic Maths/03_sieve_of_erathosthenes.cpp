#include <bits/stdc++.h>
using namespace std;


int countPrime(int n)
{
    int count = 0;

    vector<bool> prime(n + 1, true);

    // 0 and 1 is always non-prime
    prime[0] = prime[1] = false;

    // check for prime no.
    for (int i = 2; i < n; i++)
    {
        // if found increment "count"
        if (prime[i])
        {
            count++;
            // mark all the multiple of prime was non-prime
            for (int j = 2 * i; j < n; j = j + i)
                prime[j] = 0;
        }
    }

    return count;
}

int main()
{
    int n;
    cout << "enter no : ";
    cin >> n;

    cout << "total prime present between 1 to " << n << " : " << countPrime(n);
}