#include <iostream>
using namespace std;

void reverse(string &str)
{
    int s = 0;
    int e = str.length() - 1;

    while (s < e)
    {
        swap(str[s], str[e]);
        s++;
        e--;
    }
}

void reverseWordFromString(string &str)
{
    string temp = "";
    for (int i = 0; i <= str.length(); i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            reverse(temp);

            for (int j = 0; j < temp.size(); j++)
            {
                str[i - temp.size() + j] = temp[j];
            }
            temp = "";
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
}

int main()
{
    string str = "the sky is blue";

    reverseWordFromString(str);

    cout << str << endl;

    return 0;
}

/*

    leetcode

        - reverse words in a string
        - https://leetcode.com/problems/reverse-words-in-a-string/

    -----------------------------------------------------------------------------------------------------------------------
    statement

    - Given an input string s, reverse the order of the words.

    - A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

    - Return a string of the words in reverse order concatenated by a single space.

    - Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
    -----------------------------------------------------------------------------------------------------------------------

    Input: s = "the sky is blue"
    Output: "blue is sky the"

    ---------------------

    Input: s = "  hello world  "
    Output: "world hello"
    Explanation: Your reversed string should not contain leading or trailing spaces.

    -----------------------------------------------------------------------------------------------------------------------
    Approach

    - iterate each char from string (0-> str.length())
        - if, found " " empty space or "\0" end of the string
            - then reverse temp
            - store temp in original string
        - else 
            store element in string
    -----------------------------------------------------------------------------------------------------------------------

*/
