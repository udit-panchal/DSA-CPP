#include <iostream>
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
        cout << "Memory freed with data: " << data << endl;
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
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void sort_0s_1s_2s()
    {
        if (head == NULL || head->next == NULL)
            return;

        Node *zeroHead = new Node(-1);
        Node *oneHead = new Node(-1);
        Node *twoHead = new Node(-1);

        Node *zeroTail = zeroHead;
        Node *oneTail = oneHead;
        Node *twoTail = twoHead;

        Node *curr = head;

        while (curr != NULL)
        {
            if (curr->data == 0)
                insertAtTail(zeroTail, curr);
            else if (curr->data == 1)
                insertAtTail(oneTail, curr);
            else
                insertAtTail(twoTail, curr);

            curr = curr->next;
        }

        zeroTail->next = oneHead->next ? oneHead->next : twoHead->next;
        oneTail->next = twoHead->next;
        twoTail->next = NULL;

        head = zeroHead->next;

        delete zeroHead;
        delete oneHead;
        delete twoHead;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

private:
    void insertAtTail(Node *&tail, Node *curr)
    {
        tail->next = curr;
        tail = curr;
    }
};

int main()
{
    LinkedList list;

    list.insert(1);
    list.insert(0);
    list.insert(0);
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(2);

    cout << "Original list: ";
    list.print();

    list.sort_0s_1s_2s();

    cout << "Sorted list: ";
    list.print();

    return 0;
}
