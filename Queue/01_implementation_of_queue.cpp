#include <bits/stdc++.h> // Include necessary headers

using namespace std;

class MyQueue // Define the MyQueue class
{
public:
    int size;    // Size of the queue
    int *arr;    // Array to store queue elements
    int rear;    // Rear pointer to track the last element
    int front;   // Front pointer to track the first element

    // Constructor to initialize the queue
    MyQueue(int size)
    {
        this->size = size;         // Assign size
        arr = new int[size];       // Allocate memory for the array
        rear = -1;                 // Initialize rear pointer to -1 (empty queue)
        front = -1;                // Initialize front pointer to -1 (empty queue)
    }

    // Function to add an element to the queue
    void enqueue(int data)
    {
        if (rear != size - 1)      // Check if the queue is not full
        {
            if (front == -1)      // If the queue is empty, update front pointer
                front++;

            rear++;               // Move the rear pointer forward
            arr[rear] = data;     // Assign data to the rear position in the array
        }
        else
        {
            cout << "Overflow condition" << endl; // Print overflow message if the queue is full
        }
    }

    // Function to remove an element from the queue
    void dequeue()
    {
        if (front != rear)        // Check if the queue is not empty
        {
            front++;              // Move the front pointer forward
        }
        else
        {
            cout << "Queue is empty" << endl; // Print empty queue message if the queue is empty
            front = 0;             // Reset front pointer to 0
            rear = -1;             // Reset rear pointer to -1
        }
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return (front == rear);   // Return true if front and rear are equal (empty queue)
    }

    // Function to get the front element of the queue
    int getFront()
    {
        if (!isEmpty())           // Check if the queue is not empty
            return arr[front];    // Return the element at the front of the queue
        else
            return -1;            // Return -1 if the queue is empty
    }
};

int main()
{
    // Create an instance of the MyQueue class with size 5
    MyQueue queue(5);

    // Enqueue some elements to the queue
    queue.enqueue(11);
    queue.enqueue(22);
    queue.enqueue(33);
    queue.enqueue(44);

    // Display the front element of the queue
    cout << "Front element: " << queue.getFront() << endl;

    // Dequeue an element from the queue
    queue.dequeue();
    cout << "Front element after dequeue: " << queue.getFront() << endl;

    // Dequeue another element from the queue
    queue.dequeue();
    cout << "Front element after dequeue: " << queue.getFront() << endl;

    // Check if the queue is empty
    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
