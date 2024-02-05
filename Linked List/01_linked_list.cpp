#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        int value = this->data;

        // Memory deallocation
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory free with data : " << value << endl;
    }
};

// INSERTION OF NODE AT HEAD , AT TAIL AND AT ANY SPECIFIC POSITION

// Insert a new node at the beginning of the linked list
void insertAtHead(Node *&head, int d)
{
    // Create a new node with the given data
    Node *newNode = new Node(d);

    // Set the 'next' pointer of the new node to the current head of the linked list
    newNode->next = head;

    // Update the head of the linked list to be the new node
    head = newNode;
}

// Insert a new node at the end of the linked list
void insertAtTail(Node *&tail, int d)
{
    // Create a new node with the given data
    Node *newNode = new Node(d);

    // Set the 'next' pointer of the current tail to the new node
    tail->next = newNode;

    // Update the tail to be the new node
    tail = newNode;
}

// Insert a new node at a specific position in the linked list
void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    // position 1, inserting at start
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    // Create a temporary pointer 'temp' and initialize it with the head of the linked list
    Node *temp = head;
    int count = 1;

    // Go to the position where the new node will be inserted
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // insert at last position
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating new node
    Node *newNode = new Node(d);

    // Putting the new node between two nodes
    newNode->next = temp->next;
    temp->next = newNode;
}

// DELETION OF NODE AT HEAD , AT TAIL AND AT ANY SPECIFIC POSITION

// Delete a node at a specific position in the linked list
void deleteNode(int position, Node *&head, Node *&tail)
{
    // for deleting the first node
    if (position == 1)
    {
        // create a temporary node and initialize it with the head
        Node *temp = head;

        // move head forward to the next node
        head = head->next;

        // unlink the node's next pointer
        temp->next = NULL;

        // delete the node
        delete temp;
    }
    else
    {
        // current node pointer, initialized to the head
        Node *curr = head;

        // previous node pointer, initially set to NULL
        Node *prev = NULL;

        // counter to keep track of the position while traversing the list
        int count = 1;

        // go to the position where the deletion should occur
        while (count < position)
        {
            // move prev to the current position
            prev = curr;

            // move curr to the next node
            curr = curr->next;

            // increment the counter
            count++;
        }

        // update the tail if the node to be deleted is the last node
        if (curr == tail) tail = prev;

        // unlink the current node by updating the next pointer of the previous node
        prev->next = curr->next;

        // set the next pointer of the current node to NULL
        curr->next == NULL;

        // delete the current node
        delete curr;
    }
}

void deleteNodeWithValue(int value, Node *&head, Node *&tail)
{
    // Current node pointer, initialized to the head
    Node *curr = head;

    // Previous node pointer, initially set to NULL
    Node *prev = NULL;

    // Traverse the linked list to find the node with the specified value
    while (curr != NULL && curr->data != value)
    {   // Move prev to the current position
        prev = curr;

        // Move curr to the next node
        curr = curr->next;
    }

    // If the value is not found
    if (curr == NULL)
    {
        cout << "Node with value " << value << " not found." << endl;
        return;
    }

    // Update the tail if the node to be deleted is the last node
    if (curr == tail) tail = prev;

    // Unlink the current node by updating the next pointer of the previous node
    if (prev != NULL) prev->next = curr->next;

    // If the node to be deleted is the head, update the head
    else head = curr->next;

    // Set the next pointer of the current node to NULL
    curr->next = NULL;

    // Delete the current node
    delete curr;
}


// PRINTING LINKED LIST

// Print the elements of the linked list
void print(Node *&head)
{
    cout << "linked list : ";
    // Create a temporary pointer 'temp' and initialize it with the head of the linked list
    Node *temp = head;

    // iterate through the linked list until the end is reached
    while (temp != NULL)
    {
        // Print the data of the current node
        cout << temp->data << " -> ";

        // Move to the next node in the linked list
        temp = temp->next;
    }
    cout << "NULL " << endl;
}


int main()
{
    // Create the first node
    Node *node1 = new Node(2);
    // cout << node1->data << endl;
    // cout << node1->next << endl
    //      << endl;

    // Initialize head and tail with the first node
    Node *head = node1;
    Node *tail = node1;

    // Insert nodes at different positions
    insertAtHead(head, 12);
    insertAtHead(head, 19);
    insertAtTail(tail, 7);
    insertAtPosition(tail, head, 2, 1111);

    // Print the linked list
    print(head);

    // Delete a node at a specific position
    deleteNode(5, head, tail);

    // Print the linked list after deletion
    print(head);

    // Print the head and tail values
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;

    return 0;
}