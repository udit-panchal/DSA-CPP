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

    void reverse_linkedList(Node *&temp)
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
    }

    bool isPalindrome()
    {
        if (head == NULL)
            return false;

        if (head->next == NULL)
            return true;

        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        reverse_linkedList(slow);

        Node *one = head;
        Node *two = slow;
        while (one != NULL && two != NULL)
        {
            if (one->data != two->data)
                return false;

            one = one->next;
            two = two->next;
        }

        return true;
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
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(20);
    list.insert(10);

    // bool result = list.isPalindrome();

    // (result) ? cout << "it is palindrome." : cout << "it is not a palindrome.";

    return 0;
}
