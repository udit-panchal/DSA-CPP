#include <iostream>
using namespace std;

char checkOccurance(string str)
{
    int arr[26] = {0};

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        int number = 0;

        if (ch >= 'a' && ch <= 'z')
            number = ch - 'a';

        else if (ch >= 'A' && ch <= 'Z')
            number = ch - 'A';

        arr[number]++;
    }

    int maxi = -1, ans = 0;

    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }

    char result = 'a' + ans;

    return result;
}

int main()
{

    // string str = "apple";//p

    // string str = "output";//t

    string str = "test"; // t

    cout << checkOccurance(str);

    return 0;
}