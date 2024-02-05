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

    Node* floydDetectionLoop()
    {
        if(head==NULL)
            return NULL;
        
        Node* fast = head;
        Node* slow = head;

        while(fast!=NULL && slow!= NULL)
        {
            fast=fast->next;
            slow = slow->next;
            if(fast!=NULL)
                fast = fast->next;
            
            if(fast == slow)
                return slow;
        }
        return NULL;
    }

    Node* getStartingNode()
    {
        if(head==NULL)
            return NULL;
        
        Node* intersection = floydDetectionLoop();
        Node* slow = head;

        while(slow!=intersection)
        {
            intersection = intersection->next;
            slow= slow->next;
            if(slow==intersection)
                break;
        }
        return slow;
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
    list.insertAtBegin(5);
    list.insertAtBegin(6);

    list.print();

    // Create a loop for testing
    list.tail->next = list.head->next->next;

    Node *startNode = list.getStartingNode();

    cout << "Starting Node of Loop is : " << startNode->data << endl;

    return 0;
}