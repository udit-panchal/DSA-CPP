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
        if (head == NULL && head->next == NULL)
            return;

        Node *currentNode = head;

        while (currentNode != NULL)
        {
            Node *comparisonNode = currentNode;

            while (comparisonNode->next != NULL)
            {
                if (currentNode->data == comparisonNode->next->data)
                {
                    Node *nodeToDelete = comparisonNode->next;
                    comparisonNode->next = comparisonNode->next->next;
                    delete nodeToDelete;
                }
                else
                    comparisonNode = comparisonNode->next;
            }
            currentNode = currentNode->next;
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
        cout << "NULL" << endl;

        cout << "Head :" << head->data << endl;
    }
};

int main()
{

    LinkedList list;

    list.insert(91);
    list.insert(33);
    list.insert(21);
    list.insert(23);
    list.insert(91);
    list.insert(33);
    list.insert(21);
    list.insert(45);
    list.insert(91);

    list.print();

    list.remove_duplicate();

    list.print();
    return 0;
}