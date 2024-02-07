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

    Node *reverse(Node *&temp)
    {
        Node *prev = NULL;
        Node *curr = temp;
        Node *forw = NULL;

        while (curr != NULL)
        {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        temp = prev;
        return temp;
    }

    void insertAtTail(Node *&head, Node *&tail, int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
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

    Node *addTwoList(Node *first, Node *second)
    {
        first = reverse(first);
        second = reverse(second);

        Node *rHead = NULL;
        Node *rTail = NULL;

        int carry = 0;

        while (first != NULL || second != NULL || carry != 0)
        {
            int val1 = (first != NULL) ? first->data : 0;
            int val2 = (second != NULL) ? second->data : 0;

            int sum = carry + val1 + val2;
            int digit = sum % 10;

            insertAtTail(rHead, rTail, digit);

            carry = sum / 10;

            if (first != NULL)
                first = first->next;

            if (second != NULL)
                second = second->next;
        }

        Node* result = reverse(rHead);
        return result;
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
    }
};

int main()
{
    LinkedList list1;

    list1.insert(1);
    list1.insert(0);
    list1.insert(0);

    LinkedList list2;

    list2.insert(9);
    list2.insert(0);
    list2.insert(0);

    Node *temp = list1.addTwoList(list1.head, list2.head);
    list1.print(temp);

    cout << endl;

    return 0;
}
