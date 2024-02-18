#include <bits/stdc++.h>
using namespace std;

string defanging_IP_Address(string address)
{
    /*
        Brute Force Approach

        Time = O(n);
        Space = O(n+m);
    */

    string result;
    int i = 0;
    while (i <= address.length())
    {
        if(address[i] == '.')
        {
            result += "[.]";
        }
        else{
            result += address[i];
        }
        i++;
    }

    return result;
}

string defanging_IP_Address_Optimized(string address)
{
    /*
        Optimized Approach

        Time = O(n);
        Space = O(1);
    */
    string str = "[.]";
    int i = 0;

    while (i < address.length())
    {
        if (address[i] == '.')
        {
            address.insert(i, str);
            i += str.length();
            address.erase(i, 1);
        }
        else
        {
            i++;
        }
    }
    return address;
}

int main()
{
    string str = "1.1.1.1";

    string result = defanging_IP_Address(str);

    for (int i = 0; i < result.length() - 1; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

/*

    1108. Defanging an IP Address (leetcode)
    Easy
    Given a valid (IPv4) IP address, return a defanged version of that IP address.

    A defanged IP address replaces every period "." with "[.]".

    Input: address = "1.1.1.1"
    Output: "1[.]1[.]1[.]1"

    Input: address = "255.100.50.0"
    Output: "255[.]100[.]50[.]0"
*/