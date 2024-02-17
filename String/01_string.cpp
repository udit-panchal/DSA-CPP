#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int main()
{   


    /* 
        - we can directly print like this cout<<stringName<<endl;
        - two type of string 
    
    */

    /*  
        (I) C-style

        - c-style string is the array of char type 

    */

    char cStyle[10] = {'a','b','c','d','e','f','g','h','i','j'};
    // char cStyle[10] = "abcdefghij";

    // for(int i = 0; i<10; i++)
    // {
    //     cout<<cStyle[i];
    // }cout<<endl;

    cout<<cStyle<<endl;

    // -------------------------------------------------------------

    /*  
        (II) String class in c++

        - the standard c++ library provides a string class type
        - we can use direct "string" keyword

    */

    string abc = "abcdefghi";
    cout<<abc<<endl;
    
    /* 
        to convert std::string to c-style string
            const char* cstr = str2.c_str();
    */

    string str2 = "hello world";

    const char* cstr = str2.c_str();

    cout<<strlen(cstr)<<endl;

    return 0;

}