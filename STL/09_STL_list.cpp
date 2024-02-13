#include <iostream>
#include <list>

using namespace std;

int main()
{
    // Creating a list
    list<int> l;

    // Initializing a list with 5 elements, all set to 100
    list<int> n(5, 100);

    // Printing elements of list n
    cout << "Elements of list n: " << endl;
    for (int i : n)
    {
        cout << i << " ";
    }
    cout << endl;

    // Adding elements to the end and beginning of the list
    l.push_back(1);
    l.push_front(3);

    // Printing elements of list l
    cout << "Elements of list l after adding elements: " << endl;
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    // Erasing the first element of the list
    l.erase(l.begin());

    // Printing elements of list l after erasing the first element
    cout << "Elements of list l after erasing the first element: " << endl;
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    // Getting the size of the list
    cout << "Size of list l: " << l.size() << endl;

    return 0;
}

/**

    - list: It's a container in C++ STL that implements a doubly linked list. Unlike vectors, lists do not have random access, and accessing elements by index is not efficient. However, lists offer constant-time insertion and deletion of elements at both the beginning and end of the list.

    - list<int> l;: This line creates an empty list of integers named l.

    - list<int> n(5, 100);: This line initializes a list named n with 5 elements, all set to the value 100.

    - l.push_back(1); and l.push_front(3);: These lines add elements to the end and beginning of the list l, respectively.

    - l.erase(l.begin());: This line erases the first element of the list l.

    - l.size(): This function returns the number of elements in the list l.

*/
