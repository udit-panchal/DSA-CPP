#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;       // Array to store queue elements
    int size;       // Size of the queue
    int front;      // Front pointer
    int rear;       // Rear pointer

public:
    // Constructor to initialize the circular queue
    CircularQueue(int s) : size(s), arr(new int[s]), front(-1), rear(-1) {}

    // Destructor to free memory allocated for the array
    ~CircularQueue() {
        delete[] arr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % size == front;
    }

    // Function to enqueue an element into the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty())
            front = 0;
        rear = (rear + 1) % size;
        arr[rear] = value;
    }

    // Function to dequeue an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    // Function to get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    // Function to display all elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        cout << "Queue elements: ";
        do {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout << endl;
    }
};

int main() {
    // Create a circular queue with size 5
    CircularQueue queue(5);

    // Enqueue elements into the queue
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    // Display the elements of the queue
    queue.display();

    // Get the front element of the queue
    cout << "Front element: " << queue.getFront() << endl;

    // Dequeue two elements from the queue
    queue.dequeue();
    queue.dequeue();

    // Display the elements of the queue after dequeue
    queue.display();

    // Check if the queue is full
    cout << "Is queue full? " << (queue.isFull() ? "Yes" : "No") << endl;

    return 0;
}
