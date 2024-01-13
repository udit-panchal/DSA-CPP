#include <iostream>
using namespace std;

int main() {
    int n ;
    cin>>n;

    // created array of pointer
    int** arr = new int*[n];

    // creating array for each pointer
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];

    // taking input
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    // output
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    // free memory
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}
