#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkEqual(int a[26], int b[26])
{
    for (int i = 0; i < 26; i++)
        if (a[i] != b[i])
            return 0;

    return 1;
}

bool permutation_Of_String(string str1, string str2)
{

    int count1[26] = {0};

    // count1 store no. of char stored in str1(string)
    for (int i = 0; i < str1.length(); i++)
    {
        int index = str1[i] - 'a';
        count1[index]++;
    }

    int i = 0;
    int windowSize = str1.length();
    int count2[26] = {0};

    // count2 store no. of char stored in str2(string)
    // for first window.
    while (i < windowSize && i < str2.length())
    {
        int index = str2[i] - 'a';
        count2[index]++;
        i++;
    }

    // check if the both count1 and count2 array will equal then return true
    if (checkEqual(count1, count2))
        return 1;

    while (i < str2.length())
    {
        char newChar = str2[i];
        int newIndex = newChar - 'a';
        count2[newIndex]++;

        char oldChar = str2[i - windowSize]; // Update to get the outgoing character
        int oldIndex = oldChar - 'a';
        count2[oldIndex]--;

        i++;

        if (checkEqual(count1, count2))
            return true;
    }

    return 0;
}

int main()
{
    string str1 = "ab";
    string str2 = "eidbaooo";

    bool ans = permutation_Of_String(str1, str2);

    (ans == 1) ? cout << "true" : cout << "false";
}

/*

    leetcode

        -   567. Permutation in String
        -   https://leetcode.com/problems/permutation-in-string/

    -----------------------------------------------------------------------------------------------------------------------
    statement

        - Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

        - In other words, return true if one of s1's permutations is the substring of s2.

    -----------------------------------------------------------------------------------------------------------------------

    Input
        s1 = abc
        s2 = eidbaooo

    Output : True

    ------------------------------

    Input
        s1 = ab
        s2 =  eidboaoo

    Output : False

    -----------------------------------------------------------------------------------------------------------------------
    Approach

    - 2 count array will create size of 26 for 26 alphabet
    - count1 will store count of char apperse in a string1 (a - 1, z - 26, b - 2 and if again comes then a- 2)
        - for(0->str.length()-1)
    - count2 will store count of char apperse in a string2 
        - while(i<windowSize{"str1.length()"} && i<str2.length())

    - check for first window if both array is equal if yes then return 1;

    - check for remaining all window
        - while(i<str2.length())
            - Increment the count of the new character entering the window in count2.
            - Decrement the count of the character leaving the window in count2.
            - Move the window forward by incrementing i.
            
            
    -----------------------------------------------------------------------------------------------------------------------

*/
