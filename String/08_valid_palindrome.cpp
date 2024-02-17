#include <iostream>
using namespace std;

bool valid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return 1;
    }
    return 0;
}

char toLowerCase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        return ch;
    else
        return ch + 32;
}

bool checkPalindrome(string str)
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

bool isPalindrome(string s)
{
    string temp = "";

    for(int i = 0; i<s.length(); i++)
    {
        if(valid(s[i]))
        {   
            temp.push_back(valid(s[i]));
        }
    }

    for(int i = 0; i<temp.length(); i++)
    {
        temp[i] = toLowerCase(temp[i]);
    }

    return checkPalindrome(temp);
}

int main()
{
    string s = "A man, a plan, a canal: Panama";

    bool result = isPalindrome(s);

    cout<<result<<endl;

    (result == 1) ? cout<<"true" : cout<<"false" ;


    return 0;
}