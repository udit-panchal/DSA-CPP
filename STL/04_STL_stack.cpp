#include<iostream>
#include<stack>

using namespace std;

int main()
{
    // Declaring a stack of strings
    stack<string> s;

    // Pushing elements onto the stack
    s.push("udit 1");
    s.push("udit 2");
    s.push("udit 3");

    // Printing the top (last) element of the stack
    cout << "Last element: " << s.top() << endl;

    // Removing the top element from the stack
    s.pop();

    // Printing the top element of the stack after popping
    cout << "Top element after pop: " << s.top() << endl; 

    // Printing the size of the stack
    cout << "Size of stack: " << s.size() << endl;

    // Checking if the stack is empty
    cout << "Empty or not: " << s.empty() << endl;

    return 0;
}

/*

    - stack<string> s;: Declares a stack named s that holds elements of type string.

    - s.push("udit 1"); s.push("udit 2"); s.push("udit 3");: Pushes elements onto the stack.

    - s.top(): Returns a reference to the top (last) element of the stack without removing it.

    - s.pop(): Removes the top (last) element from the stack.

    - s.size(): Returns the number of elements currently in the stack.

    - s.empty(): Returns true if the stack is empty; otherwise, returns false.
*/