#include <bits/stdc++.h>
using namespace std;

int GCD(int a,int b)
{
    if(a==0)
        return b;

    if(b==0)
        return a;

    while(a!=b){
        
        if(a>b)
            a = a-b;
        
        else
            b=b-a;

    }

    return a;
}

int main()
{
    int a, b;
    cout << "enter a and b : ";
    cin >> a >> b;

    cout << "GCD of " << a << " and " << b << " : " << GCD(a, b);
}