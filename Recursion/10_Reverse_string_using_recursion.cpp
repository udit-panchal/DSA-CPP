#include <bits/stdc++.h>
using namespace std;

void reverseString(string &str, int start, int end)
{
    if (start > end)
        return;

    swap(str[start++], str[end--]);

    reverseString(str, start, end);
}

int main()
{

    string str = "ABCDE";
    int size = str.size();

    reverseString(str, 0, size - 1);

    cout << str << endl;

    return 0;
}