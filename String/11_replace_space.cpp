// replace space with @40

#include <iostream>
using namespace std;

string replaceSpaces(string &str)
{
    string temp = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
            temp.push_back(str[i]);
    }

    return temp;
}

int main()
{
    string str = "my name is khan";

    string ans = replaceSpaces(str);

    cout << ans << endl;

    return 0;
}

/*

    coding ninja

        - Replace Spaces
        - https://www.codingninjas.com/studio/problems/replace-spaces_1172172

    -----------------------------------------------------------------------------------------------------------------------
    statement
    
    -   You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.
    -----------------------------------------------------------------------------------------------------------------------

    Input : Hello
    Input : I love coding
    Input : Coding Ninjas India
    

    Output : Hello 
    Output : I@40love@40coding
    Output : Coding@40Ninjas@40India    

    -----------------------------------------------------------------------------------------------------------------------
    Approach

    -   create a empty "temp" string
    - iterate string (0-> str.length())
        - push element into "temp" string
        - when found empty space
            - push @,4 and 0;
    - return temp;
    -----------------------------------------------------------------------------------------------------------------------

*/

