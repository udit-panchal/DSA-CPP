#include <iostream>
#include <vector>
using namespace std;

bool checkPalincdrome(vector<char> str)
{
    int s = 0;
    int e = str.size() - 1;

    while (s < e)
    {
        if (str[s] != str[e])
        {
            return 0;
        }
        s++;
        e--;
    }

    return 1;
}

char toLowerCase(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return ch + 32;
    else{
        return ch;
    }
}

int main()
{

    vector<char> str;

    str.push_back('a');
    str.push_back('b');
    str.push_back('c');
    str.push_back('b');
    str.push_back('a');

    // bool check = checkPalincdrome(str);
    
    for(int i = 0; i<str.size(); i++)
    {
        str[i] = toLowerCase(str[i]);
    }

    cout << "checked : " << checkPalincdrome(str) << endl;
}
