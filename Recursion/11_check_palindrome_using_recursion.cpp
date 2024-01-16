#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str,int s, int e)
{
    if(str[s] != str[e] )
        return false;

    if(str[s] == str[e] || s>e)
        return true;
    
    s++;
    e--;
    
    return checkPalindrome(str, s, e);

}


int main()
{

    string str = "abcba";
    int size = str.length()-1;

    bool ans = checkPalindrome(str, 0, size);

    cout << "isPalindrome ? : "<<ans<< endl;

    return 0;
}