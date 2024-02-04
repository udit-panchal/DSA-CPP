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


    // APPROACH - 1 : iterative way

    void iterative_Reverse()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        Node *prev = NULL;
        Node *curr = head;
        Node *forward = NULL;

        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
    }


    // APPROACH - 2 : revursive

    Node* reverse1(Node* curr, Node* prev)
    {
        if(curr == NULL)
        {
            head = prev;
            return prev;
        }

        Node* forward = curr->next;
        curr->next = prev;

        return reverse1(forward, curr);
    }

    void recursive_Reverse()
    {
        head = reverse1(head,NULL);
    }

    // APPROACH 3 : 

    Node* reverse_Recursive(Node* head, Node* curr, Node* prev)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node* remainingNode = reverse_Recursive(head->next, curr, prev);

        head ->next ->next = head;
        head->next = NULL;

        return remainingNode;
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

    // list.iterative_Reverse();
    // list.recursive_Reverse();
    
    list.print();

    return 0;
}