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

    Node *solve(Node *first, Node *second)
    {
        if(first->next == NULL)
        {
            first->next = second;
            return first;
        }

        // pointers for list one
        Node *curr1 = first;
        Node *forw1 = curr1->next;

        // pointers for list two
        Node *curr2 = second;
        Node *forw2 = curr2->next;

        while (forw1 != NULL && curr2 != NULL)
        {
            if (curr2->data >= curr1->data && curr2->data <= forw1->data)
            {
                // addition of node
                curr1->next = curr2;
                forw2 = curr2->next;
                curr2->next = forw1;

                // updating pointers
                curr1 = curr2;
                curr2 = forw2;
            }
            else
            {
                curr1 = forw1;
                forw1 = forw1->next;

                if (forw1 == NULL)
                {
                    curr1->next = curr2;
                    return first;
                }
            }
        }
        return first;
    }

    Node *mergeTwoSortedLinkedList(Node *first, Node *second)
    {
        // if first list is empty
        if (first == NULL)
            return second;

        // if second list is empty
        if (second == NULL)
            return first;
        
        Node* result = (first->data <= second->data) ? solve(first, second) : solve(second, first);

        return result;
    }

    void print(Node* head)
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

    list1.insert(10);
    list1.insert(20);
    list1.insert(30);
    list1.insert(40);
    list1.insert(50);
    list1.insert(60);

    LinkedList list2;

    list2.insert(11);
    list2.insert(18);
    list2.insert(28);
    list2.insert(39);
    list2.insert(58);
    list2.insert(99);

    cout << endl;
    cout << "List 1 : ";
    list1.print(list1.head);
    cout << endl;
    cout << "List 2 : ";
    list2.print(list2.head);
    cout << endl;

    cout << "Merge array : ";

    Node* temp = list1.mergeTwoSortedLinkedList(list1.head, list2.head);
    list1.print(temp);

    cout << endl;

    return 0;
}
