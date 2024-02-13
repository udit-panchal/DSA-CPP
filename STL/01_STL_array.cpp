#include <iostream>
#include <array>
#include<vector>

using namespace std;

int main()
{

    // STL ARRAY ===================

    // Standard C-style array
    int basic[3] = {1, 2, 3};

    // Creating an std::array
    array<int, 4> a = {2, 4, 6, 3};

    // Getting the size of the array
    int size = a.size();

    // Printing elements of the array
    cout << "Elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << endl;

    // Accessing specific elements and properties of the array
    cout << "Element at 2nd index - { .at() }: " << a.at(2) << endl; // Using .at() to access element at a specific index
    cout << "Empty or not - { .empty() }: " << a.empty() << endl;     // Checking if the array is empty
    cout << "First Element - { .front() }: " << a.front() << endl;    // Getting the first element of the array
    cout << "Last Element - { .back() }: " << a.back() << endl;       // Getting the last element of the array

    return 0;
}
