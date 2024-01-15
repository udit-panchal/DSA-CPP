#include <bits/stdc++.h>
using namespace std;

void sayDigits(string str[], int n)
{
    if (n == 0)
    {
        return;
    }

    int digit = n % 10;

    n = n / 10;

    sayDigits(str, n);
    cout << str[digit] << " ";
}

int main()
{
    int n;
    cout << "enter No : ";
    cin >> n;

    string str[10] = {"zero",
                      "one",
                      "two",
                      "three",
                      "four",
                      "five",
                      "six",
                      "seven",
                      "eight",
                      "nine"};

    sayDigits(str, n);
    return 0;
}