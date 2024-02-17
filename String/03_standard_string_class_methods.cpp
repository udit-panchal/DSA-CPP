#include <iostream>
using namespace std;

int main()
{

    // standard string class methods

    // ------------------------------------------------------------------------------ //

    /*
    (1) stringname.length()
        -> total number of character including spaces
    */

    // string str = "this is first method";
    // int len = str.length();
    // cout<<len<<endl;

    // ------------------------------------------------------------------------------ //

    /*
    (2) stringname.size()
        -> total number of character including spaces
    */

    // string str = "this is second method"
    // int size = str.size();
    // cout<<size<<endl;

    // ------------------------------------------------------------------------------ //

    /*
    (3) stringName.at(index)
        -> return the characterat the specific index
    */

    // string str = "abcdef";
    // char a = str.at(2);
    // cout<<a;

    // ------------------------------------------------------------------------------ //

    /*
    (4) stringName.insert(index, "chara cter")
        -> insert any word or character at a specific place or index
    */

    //    string str = "this udit";
    //    str.insert(4, " is");
    //    cout<<str<<endl;

    // ------------------------------------------------------------------------------ //

    /*
    (5) stringName.erase(fromIndex, no.ofCharToErase);
        -> erase specified number of char form to
    */

    //    string str = "abcdefghijkl";
    //    str.erase(5,5);
    //    cout<<str<<endl;

    // ------------------------------------------------------------------------------ //

    /*
    (6) stringName.append("characterToInsert")
        -> add the specified character sequence at the end of the string
    */

    // string str = "hello";
    // str.append(" udit");
    // cout<<str<<endl;

    // ------------------------------------------------------------------------------ //

    /*
    (7) stringName.compare(stringName)
        -> this method compare two string
             0	if strings are equal
            >0	if the first non-matching character in str1 is greater (in ASCII) than that of str2.
            <0	if the first non-matching character in str1 is lower (in ASCII) than that of str2.
    */

    // string str1 = "hello";
    // string str2 = "hello";

    // int result = str1.compare(str2);

    // cout << result << endl;
    // ------------------------------------------------------------------------------ //

    /*
    (8) stringName.substr(from,to)
        -> new string which is a sub string of the current string
    */

    // string str = "superscript";

    // string one = str.substr(0,5);
    // string two = str.substr(5,7);

    // cout<<one<<endl;
    // cout<<two<<endl;

    // ------------------------------------------------------------------------------ //

    /*
    (9) stringName.find_first_of("char", findAfterIndex)
        -> this method find the char from start
        -> if you want to find after an index then is can but we have to provide index
    */

    //     string str = "I am udit panchal and I am a programmer";

    //    cout<<str.find_first_of("I")<<endl;
    //    cout<<str.find_first_of("p")<<endl;
    //    cout<<str.find_first_of("p",12)<<endl;

    // ------------------------------------------------------------------------------ //

    /*
    (10) stringName.find_last_of("char", findBeforeIndex)
        -> same as above but this search from last
    */
    string str = "I am udit panchal and I am a programmer";

    cout << str.find_last_of("I") << endl;
    cout << str.find_last_of("p") << endl;
    cout << str.find_last_of("p", 12) << endl;

    // ------------------------------------------------------------------------------ //

    return 0;
}