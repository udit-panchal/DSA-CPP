#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

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

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    // INSERTION

    // insert at start :
    void insertAtBegin(int data)
    {
        // create a new node
        Node *newNode = new Node(data);

        // if no node created
        if (head == NULL)
            head = tail = newNode;
        else
        {
            // create and inserting node
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int data)
    {
        // for inserting first element
        if (tail == NULL)
        {
            insertAtBegin(data);
            return;
        }

        // create and inserting node
        Node *newNode = new Node(data);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void insertAtMiddle(int data, int position)
    {
        // for inserting at beginning
        if (position == 1)
        {
            insertAtBegin(data);
            return;
        }

        Node *temp = head;

        // traverse to the position
        int count = 1;
        while (count < position - 1)
        {
            temp = temp->next;
            count++;
        }

        // for inserting at end of the list
        if (temp->next == NULL)
        {
            insertAtTail(data);
            return;
        }

        // create and inserting node
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteNode(int position)
    {
        if (position == 1)
        {
            Node *temp = head;
            temp->next->prev == NULL;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            Node *curr = head;
            Node *prev = NULL;
            int count = 1;

            while (count != position)
            {
                prev = curr;
                curr = curr->next;
                count++;
            }

            if (curr == tail)
                tail = prev;

            curr->prev = NULL;
            prev->next = curr->next;
            curr->next = NULL;

            delete curr;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL " << endl;

        cout << "Head : " << head->data << endl;
        cout << "Tail : " << tail->data << endl;
    }
};

int main()
{
    LinkedList list;

    list.insertAtBegin(2);
    list.insertAtBegin(1);

    list.insertAtTail(10);

    list.insertAtMiddle(7, 3);

    list.print();

    list.deleteNode(3);

    list.print();

    return 0;
}