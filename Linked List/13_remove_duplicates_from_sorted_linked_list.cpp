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

    void remove_duplicate()
    {
        if (head == NULL || head->next == NULL)
            return;

        Node *curr = head;
        Node *forward = head->next;

        while (forward != NULL)
        {
            if (curr->data == forward->data)
            {
                Node *temp = forward;
                forward = forward->next;
                temp->next = NULL;
                delete temp;
                curr->next = forward;
            }
            else
            {
                curr = forward;
                forward = forward->next;
            }
        }
    }

    void solve(Node *curr, Node *&forward)
    {
        if (curr == NULL || forward == NULL)
            return;

        if (curr->data == forward->data)
        {
            Node *temp = forward;
            forward = forward->next;
            temp->next = NULL;
            delete temp;
            solve(curr, forward);
        }
        else    
        {
            solve(forward, forward->next);
        }
    }

    void recursive_remove_duplicate()
    {
        if (head != NULL && head->next != NULL)
        {
            solve(head, head->next);
        }
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
    }
};

int main()
{

    LinkedList list;

    list.insert(4);
    list.insert(4);
    list.insert(3);
    list.insert(3);
    list.insert(2);
    list.insert(1);

    list.print();

    // list.remove_duplicate();
    list.recursive_remove_duplicate();

    list.print();
    return 0;
}