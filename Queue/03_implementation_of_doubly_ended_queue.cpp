#include <bits/stdc++.h>

using namespace std;

class MyQueue
{
public:
    int size;  // Size of the queue
    int *arr;  // Array to store queue elements
    int rear;  // Rear pointer to track the last element
    int front; // Front pointer to track the first element

    MyQueue(int size)
    {
        this->size = size;   // Assign size
        arr = new int[size]; // Allocate memory for the array
        front = -1;          // Initialize front pointer to -1 (empty queue)
        rear = -1;           // Initialize rear pointer to -1 (empty queue)
    }

    // Function to add an element to the front of the queue
    void push_front(int data)
    {
        // Check if the queue is full
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        // Check if the queue is empty
        else if (isEmpty())
        {
            front = rear = 0; // If empty, set front and rear to 0
        }
        // Check if front is at the beginning and there's space at the end
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1; // Wrap around to the end of the array
        }
        else
        {
            front--; // Move front pointer to the left
        }

        arr[front] = data; // Store data at the front position
    }

    // Function to add an element to the back of the queue
    void push_back(int data)
    {
        // Check if the queue is full
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        // Check if the queue is empty
        else if (isEmpty())
        {
            front = rear = 0; // If empty, set front and rear to 0
        }
        // Check if rear is at the end and there's space at the beginning
        else if (rear == size - 1 && front != 0)
        {
            rear = 0; // Wrap around to the beginning of the array
        }
        else
        {
            rear++; // Move rear pointer to the right
        }

        arr[rear] = data; // Store data at the rear position
    }

    // Function to remove an element from the front of the queue
    void pop_front()
    {
        // Check if the queue is empty
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        // Check if there's only one element in the queue
        else if (front == rear)
        {
            front = rear = -1; // Reset front and rear pointers
        }
        // Check if front is at the end of the array
        else if (front == size - 1)
        {
            front = 0; // Wrap around to the beginning of the array
        }
        else
        {
            front++; // Move front pointer to the right
        }
    }

    // Function to remove an element from the back of the queue
    void pop_back()
    {
        // Check if the queue is empty
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        // Check if there's only one element in the queue
        else if (front == rear)
        {
            front = rear = -1; // Reset front and rear pointers
        }

        // Check if rear is at the beginning of the array
        else if (rear == 0)
        {
            rear = size - 1; // Wrap around to the end of the array
        }
        else
        {
            rear--; // Move rear pointer to the left
        }
    }

    // Function to get the front element of the queue
    int getFront()
    {
        // Check if the queue is empty
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1; // Return -1 to indicate an empty queue
        }
        return arr[front]; // Return the element at the front position
    }

    // Function to get the rear element of the queue
    int getRear()
    {
        // Check if the queue is empty
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1; // Return -1 to indicate an empty queue
        }
        return arr[rear]; // Return the element at the rear position
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return (front == -1); // Return true if front pointer is -1, indicating an empty queue
    }

    // Function to check if the queue is full
    bool isFull()
    {
        return ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size)); // Return true if front and rear pointers are adjacent or rear is one position behind front
    }
};

int main()
{
    // Test the queue
    MyQueue queue(5);

    queue.push_front(1);
    queue.push_back(2);
    queue.push_front(3);
    queue.push_back(4);

    cout << "Front element: " << queue.getFront() << endl;
    cout << "Rear element: " << queue.getRear() << endl;

    queue.pop_front();
    queue.pop_back();

    cout << "Front element after pop_front: " << queue.getFront() << endl;
    cout << "Rear element after pop_back: " << queue.getRear() << endl;

    return 0;
}
