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

class LinkedListStack
{
public:
    Node *head;
    Node *tail;

    LinkedListStack()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL && tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        else
        {
            if (head == tail)
            {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else
            {
                Node *prev = head;
                while (prev->next != tail)
                {
                    prev = prev->next;
                }
                delete tail;
                tail = prev;
                tail->next = NULL;
            }
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
            return tail->data;
    }

    bool isEmpty()
    {
        return (head == NULL && tail == NULL) ? true : false;
    }

    void print()
    {
        Node *temp = head;
        cout << "Stack                 : ";
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedListStack st;

    st.push(10);
    st.push(20);

    st.pop();

    cout << "Stack is empty ?      : " << ((st.isEmpty() == true) ? "true" : "false") << endl;

    cout << ((st.peek() != -1) ? "peek element          : " + to_string(st.peek()) : "stack is empty") << endl;

    st.print();
}