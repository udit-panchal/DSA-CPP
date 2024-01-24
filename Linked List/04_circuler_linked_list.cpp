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
    Node *tail;

    LinkedList()
    {
        this->tail = NULL;
    }

    void insert(int data, int element)
    {
        if (tail == NULL)
        {
            Node *newNode = new Node(data);
            newNode->next = newNode;
            tail = newNode;
            return;
        }
        else
        {
            Node *temp = tail;

            do
            {

                if (temp->data == element || temp->next == tail)
                {
                    Node *newNode = new Node(data);
                    newNode->next = temp->next;
                    temp->next = newNode;

                    if (temp == tail)
                        tail = newNode;

                    break;
                }

                temp = temp->next;

            } while (temp != tail);
        }
    }

    void deleteNode(int element)
    {

        if (tail == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        else
        {

            Node *prev = tail;
            Node *curr = prev->next;

            while (curr->data != element)
            {
                prev = curr;
                curr = curr->next;
            }

            prev->next = curr->next;

            if(curr == prev) tail = NULL;

            if(tail == curr) tail = prev;
            curr->next = NULL;
            delete curr;
            // If the node to be deleted is the head node
        }
    }

    void print()
    {
        if (tail == NULL)
        {
            cout << "List is empty, please check again" << endl;
            return;
        }

        Node *temp = tail;

        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail);
    }
};

int main()
{
    LinkedList list;

    list.insert(11, 1);
    list.insert(22, 2);
    list.insert(33, 3);
    list.insert(44, 3);
    list.insert(3553, 3);
    list.print();

    list.deleteNode(33);
    list.print();

    return 0;
}