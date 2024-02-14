
#include <bits/stdc++.h>
using namespace std;

class petrolPump
{
public:
    int petrol;
    int distance;
};

int printTour(petrolPump p[], int n)
{
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        balance = balance + p[i].petrol - p[i].distance;
        if (balance < 0)
        {
            deficit = deficit + balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (deficit + balance >= 0)
        return start;

    else
        return -1;
}
int main()
{
    petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};

    int n = sizeof(arr) / sizeof(arr[0]);
    int start = printTour(arr, n);

    (start == -1) ? cout << "No solution" : cout << "Start = " << start;

    return 0;
}