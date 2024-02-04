#include <iostream>
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

    LinkedList()
    {
        this->head = NULL;
    }

    void insert(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    Node *reverseInKGroup(int k, Node *head)
    {
        if (head == NULL)
            return NULL;

        Node *prev = NULL;
        Node *curr = head;
        Node *forward = NULL;

        int cnt = 0;
        while (curr != NULL && cnt < k)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            cnt++;
        }
        
        if(head!=NULL)
            head->next = reverseInKGroup(k, forward);

        return prev;
    }

    void reverse(int k)
    {
        head = reverseInKGroup(k, head);
    }

    void print()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }cout <<"NULL"<< endl;

        cout << "Head :" << head->data << endl;
    }
};

int main()
{

    LinkedList list;

    list.insert(8);
    list.insert(7);
    list.insert(6);
    list.insert(5);
    list.insert(4);
    list.insert(3);
    list.insert(2);
    list.insert(1);

    list.print();

    list.reverse(2);

    list.print();

    return 0;
}