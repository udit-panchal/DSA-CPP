#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // Creating two priority queues:
    // - `maxi` where the elements are sorted in decreasing order (default behavior).
    // - `mini` where the elements are sorted in increasing order, achieved by providing a custom comparator.
    priority_queue<int> maxi;                            // Default: Max-heap
    priority_queue<int, vector<int>, greater<int>> mini; // Min-heap

    // Adding elements to the `maxi` priority queue
    maxi.push(56);
    maxi.push(45);
    maxi.push(87);
    maxi.push(35);

    // Printing the size of the `maxi` priority queue
    cout << "Size of maxi priority queue: " << maxi.size() << endl;

    // Printing elements of the `maxi` priority queue by repeatedly popping the top element until the queue is empty
    cout << "Elements of maxi priority queue (in descending order): ";
    int n = maxi.size();
    for (int i = 0; i < n; i++)
    {
        cout << maxi.top() << " "; // Accessing the top element of the priority queue
        maxi.pop();                // Removing the top element of the priority queue
    }
    cout << endl;

    // Adding elements to the `mini` priority queue
    mini.push(54);
    mini.push(97);
    mini.push(32);
    mini.push(87);
    mini.push(98);

    // Printing elements of the `mini` priority queue by repeatedly popping the top element until the queue is empty
    cout << "Elements of mini priority queue (in ascending order): ";
    int m = mini.size();
    for (int i = 0; i < m; i++)
    {
        cout << mini.top() << " "; // Accessing the top element of the priority queue
        mini.pop();                // Removing the top element of the priority queue
    }
    cout << endl;

    // Checking if the `mini` priority queue is empty
    cout << "Check if mini priority queue is empty: " << mini.empty() << endl;

    return 0;
}

/*
    - priority_queue: It's a container adapter provided by the C++ Standard Library that provides a queue where the elements are ordered according to some comparison criterion.

    - priority_queue<int> maxi;: This line declares a priority queue named maxi where the elements are sorted in decreasing order by default, i.e., the maximum element is at the top.

    - priority_queue<int, vector<int>, greater<int>> mini;: This line declares a priority queue named mini where the elements are sorted in increasing order, i.e., the minimum element is at the top. It specifies a custom comparator greater<int> to achieve this behavior.

    - maxi.push(56);: This line adds an element 56 to the maxi priority queue.

    - maxi.top(): This function returns the top element of the maxi priority queue without removing it.

    - maxi.pop(): This function removes the top element of the maxi priority queue.

    - mini.empty(): This function returns true if the mini priority queue is empty; otherwise, it returns false.

*/