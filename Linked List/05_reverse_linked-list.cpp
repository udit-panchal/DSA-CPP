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

    void insert(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;

        if (head == NULL)
            head = tail = newNode;

        else
            head = newNode;
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

    void iterative_Reverse()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        Node *prev = NULL;
        Node *curr = head;
        Node *forward = NULL;

        tail = head;

        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
    }

    Node* reverse(Node* curr, Node* prev)
    {
        if(curr == NULL)
        {
            head = prev;
            return prev;
        }

        Node* nextNode = curr->next;
        curr->next = prev;

        return reverse(nextNode, curr);
    }

    void recursive_Reverse()
    {
        head = reverse(head,NULL);
    }

};

int main()
{

    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    list.print();

    // list.deleteNode(2);

    // list.print();

    // list.iterative_Reverse();
    list.recursive_Reverse();

    
    list.print();

    return 0;
}