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

    Node *sort_0s_1s_2s(Node *head)
    {
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;

        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == 0)
                zeroCount++;
            else if (temp->data == 1)
                oneCount++;
            else if (temp->data == 2)
                twoCount++;

            temp = temp->next;
        }

        temp = head;
        while (temp != NULL)
        {
            if (zeroCount){
                temp->data = 0;
                zeroCount--;
            }
            else if (oneCount){
                temp->data = 1;
                oneCount--;
            }
            else if (twoCount){
                temp->data = 2;
                twoCount--;
            }

            temp = temp->next;
        }
    }

    void print(Node *head)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;

        cout << "Head :" << head->data << endl;
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

    list.print(list.head);

    list.sort_0s_1s_2s(list.head);

    list.print(list.head);

    return 0;
}