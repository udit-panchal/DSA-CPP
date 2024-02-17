#include <iostream>
#include <vector>
using namespace std;

bool checkPalincdrome(vector<char> str)
{
    int s = 0;
    int e = str.size()-1;

    while (s < e)
    {
        if (str[s] != str[e])
        {
            return 0;
            break;
        }
        s++;
        e--;
    }

    return 1;
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

    cout<<"checked : "<<checkPalincdrome(str)<<endl;
}
