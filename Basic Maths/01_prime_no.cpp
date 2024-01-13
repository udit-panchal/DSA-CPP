#include <iostream>
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

int main()
{
    int n;
    cout<<"enter no : ";
    cin >> n;

    if (isPrime(n))
        cout << "it is prime no." << endl;
    else
        cout << "not a prime no." << endl;

    return 0;
}