#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{

    // c-style str Methods

    // ------------------------------------------------------------------------------ //

    /*
    (1) strlen(_string_name_)
      -> return the length of the string wihtout inlclude null character('\0').
      -> header file : <string.h>
    */
    // char cstr1[] = "this is c_style string 1 ";
    // char cstr2[] = "this is c_style string 2 ";
    // const char* cstr = str1.c_str();
    // cout<<strlen(cstr);

    // ------------------------------------------------------------------------------ //

    /*
    (2) strcmp(_string_name_)
      -> compares the two strings and returns an integer value.
                                    
      -> case sensetive
      -> header file : <string.h>
    */

    // char cstr1[] = "this is c_style string 1 ";
    // char cstr2[] = "this is c_style string 0 ";
    // char cstr2[] = "this is c_style string 2 ";
    // cout << strcmp(cstr1, cstr2);

    // ------------------------------------------------------------------------------ //

    /*
    (3) strcmpi(_string_name_)
      ->same as above but not case sensetive
      -> header file : <string.h>
    */

    // char cstr1[] = "this is c_style string 1 ";
    // char cstr2[] = "this is c_style string 0 ";
    // char cstr2[] = "this is c_style string 2 ";
    // char cstr2[] = "this is c_style String 1 ";
    // cout << strcmp(cstr1, cstr2);

    // ------------------------------------------------------------------------------ //

    /*
    (4) strcat(_string_name_ , _string_name_ , ......)
    -> concatenates two strings and returns the concatenated string.
    -> header file : <string.h>
    */

    // char a[] = "a";
    // char b[] = "b";

    // string c = strcat(a,b);

    // cout<<c<<endl;

    // ------------------------------------------------------------------------------ //

    /*
    (5) strcpy(_string_name_,_string_name_)
      -> copies the string str2 into string str1, including null character ('\0').
      -> header file : <string.h>
    */

    //    char str1[] = "string 1";
    //    char str2[] = "string 2";
    //    string c = strcpy(str1, str2);

    //    cout<<str1<<endl;
    //    cout<<str2<<endl;
    //    cout<<c<<endl;

    // ------------------------------------------------------------------------------ //

    /*
    (6) strupr(_string_name_)
      -> converts a string to uppercase.
      -> header file : <string.h>
    */

    // char str[] = "this is lower case";
    // strupr(str);

    // cout<<str<<endl;

    // ------------------------------------------------------------------------------ //

    /*
    (7) strlwr(_string_name_)
      -> converts a string to lowercase.
      -> header file : <string.h>
    */

    // char str[] = "THIS IS UPPER CASE";
    // strlwr(str);

    // cout<<str<<endl;

    // ------------------------------------------------------------------------------ //

    /*
    (8) strrev(_string_name_)
      -> converts a string into reverse order
      -> header file : <string.h>
    */

    //    char str[] = " This Is Non Reverse String";
    //    strrev(str);

    //    cout<<str;

    // ------------------------------------------------------------------------------ //

    /*
    (9) tolower(string_name)
      -> converts a character to lowercase.
      -> header file : <ctype.h>
    */

    // char str1 = 'H';

    // str1 = tolower(str1);
    // cout<<"str1 is: "<<str1;

    // ------------------------------------------------------------------------------ //

    /*
    (10) toupper(string_name)
      -> converts a character to lowercase.
      -> header file : <ctype.h>

    */

    // char str1 = 'h';

    // str1 = toupper(str1);
    // cout << "str1 is: " << str1;

    // ------------------------------------------------------------------------------ //

    /*
    (11) isupper(_string_name_)
        -> return non-zero if uppercase letter 
        -> return zero if not uppercase letter
        -> header file : <ctype.h>
    */
    // char str1 = 'A';
    // cout<<isupper(str1);


    // ------------------------------------------------------------------------------ //

    /*
    (12) islower(_string_name_)
        -> return non-zero if lowercase letter 
        -> return zero if not lowercase letter
        -> header file : <ctype.h>
    */
    // char str1 = 'b';
    // cout<<islower(str1);
    // ------------------------------------------------------------------------------ //

    /*
    (13) isalpha(_string_name_)
        -> return non-zero if alphabet letter 
        -> return zero if not alphabet letter
        -> header file : <ctype.h>
    */
    // char str1 = '1';
    // cout<<isalpha(str1);
    // ------------------------------------------------------------------------------ //
    
    /*
    (14) isdigit(_string_name_)
        -> return non-zero if digit b/w 0 to 9
        -> return zero if not digit b/w 0 to 9
        -> header file : <ctype.h>
    */

    // char str1 = '7';
    // cout<<isdigit(str1);
    // ------------------------------------------------------------------------------ //
        
    /*
    (15) isspace(_string_name_)
        -> return non-zero if there is space
        -> return zero if there is not space
        -> header file : <ctype.h>
    */

    // char str1 = ' ';
    // cout<<isspace(str1);
    // ------------------------------------------------------------------------------ //
    
    /*
        (14) ispunct(_string_name_)
        -> return non-zero if there is not alphabet, digit or space
        -> return zero if there is alphabet, digit or space
        -> header file : <ctype.h>
    */

    char str1 = '>';
    cout<<ispunct(str1);

    // ------------------------------------------------------------------------------ //













    
    return 0;
}

// (1234){
//     -> work with only c-style string
//     -> for using in std::string change the c-styel to string
// }