#include <iostream>
#include <deque>
using namespace std;
/*

    - deque (double-ended queue) is a dynamic array-like container that supports efficient insertion and deletion operations from both ends.
    
    - deque (double-ended queue) is a container similar to vector, but with the ability to efficiently add or remove elements from both ends.
    
    - It provides constant time complexity for insertion and deletion at both ends, unlike vectors which have linear time complexity for such operations.
    
*/

int main()
{
    // Create a deque container
    deque<int> d;

    // Add elements to the deque
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);

    // Display elements of the deque
    cout << "Initial deque contents: ";
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;

    // Remove elements from both ends of the deque
    d.pop_back();
    d.pop_front();

    // Display deque contents after removing elements from both ends
    cout << "After popping front and back elements: ";
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;

    // Display the front and back elements of the deque, and check if it's empty
    cout << "Front element: " << d.front() << endl;
    cout << "Back element: " << d.back() << endl;
    cout << "Deque empty or not: " << d.empty() << endl;

    // Display deque size before and after erasing elements
    cout << endl
         << "Before erasing, deque size: " << d.size() << endl;
    for (int i : d)
    {
        cout << i << " ";
    }
    // Erase elements from the deque
    d.erase(d.begin(), d.begin() + 1);
    cout << endl
         << "After erasing, deque size: " << d.size() << endl;
    for (int i : d)
    {
        cout << i << " ";
    }

    return 0;
}
