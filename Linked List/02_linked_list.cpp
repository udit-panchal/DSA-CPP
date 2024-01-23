#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
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

    void insertAtBegin(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;

        if (head == NULL)
            head = tail = newNode;

        else
            head = newNode;
    }

    void insertAtTail(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
            head = tail = newNode;

        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtPosition(int data, int position)
    {
        Node *curr = head;
        Node *prev = NULL;

        if (position == 1)
        {
            insertAtBegin(data);
            return;
        }

        int count = 1;

        while (count != position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        Node *newNode = new Node(data);
        prev->next = newNode;
        newNode->next = curr;
    }

    void replaceValue(int newData, int oldValue)
    {

        Node *temp = head;
        int count = 1;
        while (temp->data != oldValue)
        {
            temp = temp->next;
            count++;
        }
        if (temp != NULL)
            temp->data = newData;
        else
            cout << "Not Found. " << endl;
    }

    void deleteNode(int position)
    {
        if (position == 1)
        {
            Node *temp = head;
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
        cout << endl;

        cout << "Head :" << head->data << endl;
        cout << "Tail :" << tail->data << endl;
    }
};

int main()
{

    LinkedList list;

    list.insertAtBegin(1);
    list.insertAtBegin(2);
    list.insertAtBegin(3);
    list.insertAtBegin(4);

    list.insertAtTail(0);
    list.insertAtTail(9);
    list.insertAtTail(8);
    list.insertAtTail(7);

    list.insertAtPosition(123, 2);

    list.replaceValue(456, 123);

    list.print();

    list.deleteNode(2);

    list.print();

    return 0;
}