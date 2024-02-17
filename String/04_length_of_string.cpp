#include<iostream>
using namespace std;

int main()
{

    char str[20] = "udit panchal";

    int count = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        count ++;
    }


    cout<<"length of string "<<count<<endl;

}