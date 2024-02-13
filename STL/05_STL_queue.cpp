#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // Declaring a queue of strings
    queue<string> q;

    // Adding elements to the queue
    q.push("udit 1");
    q.push("udit 2");
    q.push("udit 3");

    // Printing the size of the queue before popping an element
    cout << "Size before pop: " << q.size() << endl;

    // Printing the first element of the queue
    cout << "First element: " << q.front() << endl;

    // Removing the first element from the queue
    q.pop();

    // Printing the first element of the queue after popping
    cout << "First element after pop: " << q.front() << endl;

    // Printing the size of the queue after popping an element
    cout << "Size after pop: " << q.size() << endl;

    return 0;
}

/*
    - queue<string> q;: Declares a queue named q that holds elements of type string.

    - q.push("udit 1");: Adds the string "udit 1" to the back of the queue.

    - q.front(): Returns a reference to the first (oldest) element in the queue.

    - q.pop(): Removes the first (oldest) element from the queue.

    - q.size(): Returns the number of elements currently in the queue.
*/