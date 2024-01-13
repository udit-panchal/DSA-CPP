#include<bits/stdc++.h>
using namespace std;

// int factorial(int n)
// {
//     //base case
//     if(n==0)
//         return 1;

//     //recursive case
//     int choti = factorial(n-1);
//     int badi = n*choti;

//     return badi;
// }

int factorial(int n)
{
    //base case
    if(n==0)
        return 1;

    //recursive case
    return n * factorial(n-1);
}



int main()
{
    int n;
    cin>>n;

    int ans = factorial(n);

    cout<<ans<<endl;

    return 0;
}

/*


    Recursion Tree
    ==============


 factorial(5)
           |
      return 5 * factorial(4)
                    |
               return 4 * factorial(3)
                            |
                       return 3 * factorial(2)
                                    |
                               return 2 * factorial(1)
                                            |
                                       return 1 * factorial(0)
                                                    |
                                               return 1  (base case)

call stack of recursion
=======================


3.     factorial(4)
4.         |
5.         |-> factorial(3)
6.         |     |
7.         |     |-> factorial(2)
8.         |     |     |
9.         |     |     |-> factorial(1)
10.        |     |     |     |
11.        |     |     |     |-> factorial(0)
12.        |     |     |     |     |
13.        |     |     |     |     |<- Base case: return 1
14.        |     |     |     |
15.        |     |     |     |<- return 1 * 1
16.        |     |     |
17.        |     |     |<- return 2 * 1
18.        |     |
19.        |     |<- return 3 * 2
20.        |
21.        |<- return 4 * 6





*/