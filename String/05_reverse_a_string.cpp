#include <iostream>
using namespace std;

void reverse(char str[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        swap(str[s++], str[e--]);
    }
}

void print(char str[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << str[i];
    }
    cout << endl;
}

int main()
{
    int n = 20;
    char str[n] = "amit shah";

    print(str, n);

    reverse(str, n);

    print(str, n);
}
