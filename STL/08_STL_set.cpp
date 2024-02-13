
#include <iostream>
#include <set>

using namespace std;

int main()
{
    // Declaring a set of integers
    set<int> s;

    // Sets store elements only once and maintain them in sorted order.

    // Inserting elements into the set
    s.insert(4);
    s.insert(4); // Inserting duplicate elements will be ignored
    s.insert(3);
    s.insert(2);
    s.insert(5);
    s.insert(0);

    // Printing elements of the set
    for (auto i : s)
    {
        cout << i << endl; // Elements will be printed in sorted order
    }
    cout << endl;

    // Erasing the first element of the set
    s.erase(s.begin());

    // Printing elements of the set after erasing the first element
    for (auto i : s)
    {
        cout << i << endl;
    }
    cout << endl;

    // Erasing the element pointed by the iterator 'it' (which points to the second element)
    set<int>::iterator it = s.begin();
    it++;
    s.erase(it); // This will erase the element '3'

    // Printing elements of the set after erasing the element '3'
    for (auto i : s)
    {
        cout << i << endl;
    }
    cout << endl;

    // Checking if certain elements are present in the set
    cout << "Is 5 present? " << s.count(5) << endl;   // Output: 1 (true), as 5 is present
    cout << "Is -5 present? " << s.count(-5) << endl; // Output: 0 (false), as -5 is not present

    // Finding an element in the set
    set<int>::iterator itr = s.find(5); // Finding the iterator pointing to the element '5'

    // Printing elements of the set starting from the element '5'
    cout << endl;
    for (auto it = itr; it != s.end(); it++)
    {
        cout << *it << " "; // Output: 5
    }
    cout << endl;

    return 0;
}

/*
    - set<int> s;: Declares a set named s that holds elements of type int. Sets ensure that each element occurs only once and are stored in sorted order.

    - s.insert(4);: Inserts the element 4 into the set.

    - s.insert(4);: Inserts the element 4 again. Since sets don't allow duplicates, this insertion will be ignored.

    - s.erase(s.begin());: Erases the first element of the set. Since sets are sorted, s.begin() points to the smallest element.

    - s.erase(it);: Erases the element pointed by the iterator it. In this case, it erases the element 3.

    - s.count(5);: Checks whether the element 5 is present in the set. It returns 1 if present, 0 otherwise.

    - set<int>::iterator itr = s.find(5);: Finds the iterator pointing to the element 5 in the set.

    - for(auto it = itr; it != s.end(); it++): Loops through the set starting from the element 5 and prints all elements.
 */