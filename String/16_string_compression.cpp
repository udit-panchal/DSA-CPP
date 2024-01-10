#include <iostream>
using namespace std;

int stringCompression(string str)
{
    int i = 0; 
    int ansIndex = 0;
    int n = str.size();

    while(i<n)
    {
        int j = i+1;
        while(j<n && str[i] == str[j])
        {
            j++;
        }

        //store oldchar 
        str[ansIndex++] = str[i];

        int count = j-1;

        if(count > 1)
        {
            //converting counting into single digit and saving in answer
            string cnt = to_string(count);
            for(char ch:cnt)
                str[ansIndex++] = ch;
        }
        i = j;
    }
    return ansIndex;
}

int main()
{
    string str = "abcabcbac";

    stringCompression(str);
}

/*

    leetcode

        - 443. string compression
        - https://leetcode.com/problems/string-compression/

    -----------------------------------------------------------------------------------------------------------------------
    statement

        - Given an array of characters chars, compress it using the following algorithm:

        - Begin with an empty string s. For each group of consecutive repeating characters in chars:
            -> If the group's length is 1, append the character to s.
            -> Otherwise, append the character followed by the group's length.

        - The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

        - After you are done modifying the input array, return the new length of the array.

        - You must write an algorithm that uses only constant extra space.
    -----------------------------------------------------------------------------------------------------------------------

    Input : chars = ["a","a","b","b","c","c","c"]

    Output : Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
    ---------------------

    Input : chars = ["a"]

    Output: Return 1

    ---------------------

    Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]

    Output: Return 4

    -----------------------------------------------------------------------------------------------------------------------
    Approach

    - iterate throught the input string 'str' using two pointer 'i' and 'j'{

        - 'i' indicate current char and 'j' increasing for one char 

        - increment 'j' until 'str[i]' and 'str[j]' are found equal and count this sequence

        - store 'str[i]' char in 'ansIndex'

        - if 'count' is > then 1
        {
            - then convert 'count' into string by using 'to_string(count)' 
            - store every digit in different char which comes after compressed char
        }
    
        - update index (i = j)
    
    }

    return ansIndex;
    -----------------------------------------------------------------------------------------------------------------------

*/
