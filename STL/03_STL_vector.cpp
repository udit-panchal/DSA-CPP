#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Declaration of vector v
    vector<int> v;

    // Declaration and initialization of vector a with size 5 and all elements initialized to 1
    vector<int> a(5, 1);

    // Printing the contents of vector a
    cout << "Print vector 'a':" << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl
         << endl;

    // Copying the contents of vector a to vector last
    vector<int> last(a);

    // Printing the contents of vector last
    cout << "Print vector 'last' assigned with 'a':" << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl
         << endl;

    // Adding elements to vector v using push_back
    v.push_back(12);
    cout << "Capacity     : " << v.capacity() << endl;
    cout << "Vector at 0  : " << v[0] << endl;
    cout << "Size         : " << v.size() << endl
         << endl;

    v.push_back(32);
    cout << "Capacity     : " << v.capacity() << endl;
    cout << "Vector at 0  : " << v[0] << endl;
    cout << "Size         : " << v.size() << endl
         << endl;

    v.push_back(45);
    cout << "Capacity     : " << v.capacity() << endl;
    cout << "Vector at 0  : " << v[0] << endl;
    cout << "Size         : " << v.size() << endl
         << endl;

    v.push_back(354);
    cout << "Capacity     : " << v.capacity() << endl;
    cout << "Vector at 0  : " << v[0] << endl;
    cout << "Size         : " << v.size() << endl
         << endl;

    v.push_back(344);
    cout << "Capacity     : " << v.capacity() << endl;
    cout << "Vector at 0  : " << v[0] << endl;
    cout << "Size         : " << v.size() << endl
         << endl;

    v.push_back(543);
    cout << "Capacity     : " << v.capacity() << endl;
    cout << "Vector at 0  : " << v[0] << endl;
    cout << "Size         : " << v.size() << endl
         << endl;

    // Storing size in a variable
    int size = v.size();

    // Printing elements of vector v before popping
    cout << "Before pop:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }

    // Popping an element from vector v
    v.pop_back();

    // Printing elements of vector v after popping
    cout << endl
         << "After pop:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl
         << endl;

    // Clearing vector v
    cout << "Before clear:" << endl;
    cout << "Clear size   : " << v.size() << endl;
    cout << "Capacity     : " << v.capacity() << endl;
    v.clear();
    cout << endl;

    // Printing vector v after clearing
    cout << "After clear:" << endl;
    cout << "Clear size   : " << v.size() << endl;
    cout << "Capacity     : " << v.capacity() << endl;

    return 0;
}

/*
    - vector<int> v;: Declares an empty vector v that holds elements of type int.

    - vector<int> a(5, 1);: Declares and initializes a vector a with 5 elements, all initialized to 1.

    - vector<int> last(a);: Copies the contents of vector a to vector last.

    - v.push_back(x);: Adds an element x to the end of vector v.

    - v.pop_back();: Removes the last element from vector v.

    - v.size();: Returns the number of elements in vector v.

    - v.capacity();: Returns the number of elements that vector v can hold without reallocation.

    - v.clear();: Removes all elements from vector v.

*/