
#include<bits/stdc++.h>
using namespace std;

string removeAjacent(string str)
{
    int i = 0;
    int n = str.size();
    stack<char> st;

    while (i < n)
    {

        if (st.empty() || st.top() != str[i])
            st.push(str[i]);
        else
            st.pop();

        i++;
    }

    string ans = "";
    while (!st.empty())
    {
        char ele = st.top();
        st.pop();
        ans += ele;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    // string str = "abbaca";
    string str = "azxxzy";

    cout << removeAjacent(str);
}

/*

    leetcode

        - 1047. Remove all adjacent duplicates in string
        - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

    -----------------------------------------------------------------------------------------------------------------------
    statement

        - You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

        - We repeatedly make duplicate removals on s until we no longer can.

        removeAjacent- Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
    -----------------------------------------------------------------------------------------------------------------------

    Input :
        s = abbaca

    Output : ca

    ---------------------

    Input :
        s = azxxzy

    Output :ay

    -----------------------------------------------------------------------------------------------------------------------
    Approach 1 - basic appoach

    -   run loop (0 -> str.length()-1)
        - if there is string[index] is equal to string[index+1]
            - then erase 2 element
            - and make i = 0 that's run loop again from 0
        - else
            - i++;

    Approach 2 - using stack

        - initialize an empty stack 
        - iterate through the input string
        - if the stack is empty or the top element of the stack is different from the current char
            - then push the char onto the stack
        - if the top element of the stack is the same as the current char
            - pop the element from stack

        now initialize an empty string ans 
        - stroe element from stack 
        - reverse string because when we copy stack to string the string stored reversed.

        - return ans.


    -----------------------------------------------------------------------------------------------------------------------

*/
