#include <iostream>
using namespace std;

string removeSubStr(string str, string sub_str)
{
    while(str.length()!=0 && str.find(sub_str) < str.length())
    {
        str.erase(str.find(sub_str), sub_str.length());
    }
    return str;
}

int main()
{
    // string str = "daabcbaabcbc";
    // string sub_str = "abc";

    string str = "axxxxyyyyb";
    string sub_str = "xy";

    string ans = removeSubStr(str, sub_str);
    cout << "Output : "<< ans << endl;

    return 0;
}

/*
----------------------------------------------------------------------------------------------------------------
- leetCode

    - 1910. Remove All Occurrences of a Substring
    - https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

-----------------------------------------------------------------------------------------------------------------
statement: 

        Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

        Find the leftmost occurrence of the substring part and remove it from s.
        
        Return s after removing all occurrences of part.

-----------------------------------------------------------------------------------------------------------------
    
    input:
       s = daabcbaabcbc
       part = abc

    output: dab

    input:
       s = axxxxyyyyb
       part = xy

    output: ab

------------------------------------------------------------------------------------------------------------------
Approach : 

    - starting a loop until "str.length != 0" and "str.find(sub_str) < str.length()"
    - use ".find()" and ".erase(from,to)" to search and erase in string.
    - erase from starting of str to length of the str.
    - str.erase(str.find(sub_str),sub_str.length()).

*/
