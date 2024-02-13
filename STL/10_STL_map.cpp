#include <iostream>
#include <map>
using namespace std;

int main()
{
    // Creating a map with integer keys and string values
    map<int, string> m;

    // Inserting key-value pairs into the map
    m[1] = "udit";         // Inserts key 1 with value "udit"
    m[13] = "hello world"; // Inserts key 13 with value "hello world"
    m[2] = "panchal";      // Inserts key 2 with value "panchal"

    // Inserting a key-value pair using the insert function
    m.insert({5, "bheem"});

    // Printing the map before erasing
    cout << "Before erase:" << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;

    // Erasing a key-value pair from the map
    cout << "After erase:" << endl;
    m.erase(13); // Erases the key-value pair with key 13

    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;

    // Checking if a key exists in the map
    cout << "find 13 = " << m.count(13) << endl;   // Output: 0, as 13 is erased
    cout << "find -13 = " << m.count(-13) << endl; // Output: 0, as -13 is not present

    // Finding an element in the map using the find function
    auto it = m.find(5);
    cout << "Elements from key 5 to end:" << endl;
    for (auto i = it; i != m.end(); i++)
    {
        cout << (*i).first << endl;
    }

    return 0;
}
/*
    - map: It's a container in C++ STL that stores elements in key-value pairs. The keys are unique, and the elements are sorted based on the keys.

    - map<int, string> m;: This line creates an empty map where keys are of type int and values are of type string.

    - m[1] = "udit";: This line inserts a key-value pair into the map, where key 1 is associated with the value "udit". If the key already exists, its value will be updated.

    - m.insert({5, "bheem"});: This line inserts a key-value pair into the map using the insert function.

    - m.erase(13);: This line erases the key-value pair with key 13 from the map.

    - m.count(13);: This function returns the number of elements with a specific key in the map. It returns 1 if the key is present, otherwise 0.

    - m.find(5);: This function returns an iterator to the element with the specified key in the map, or m.end() if the key is not found.
*/