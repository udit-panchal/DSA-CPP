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

    bool floyd_cycle_detection_algo()
    {
        if (head == NULL)
            return false;

        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && slow != NULL)
        {
            slow = slow->next;
            fast = fast->next;

            if (fast != NULL)
                fast = fast->next;

            if (fast == slow)
                return true;
        }

        return false;
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

    list.print();

    // Create a loop for testing
    list.head->next->next->next = list.head;

    bool hasLoop = list.floyd_cycle_detection_algo();
    
    if (hasLoop)
        cout << "The linked list has a loop." << endl;
    else
        cout << "The linked list does not have a loop." << endl;

    return 0;
}