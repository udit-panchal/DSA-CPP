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

    bool isPalindrome()
    {
        if (head == NULL)
            return false;

        if (head->next == NULL)
            return true;

        vector<int> arr;

        Node *temp = head;
        while (temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        int i = 0;
        int j = arr.size()-1;

        while (i < j)
        {
            if (arr[i] != arr[j])
                return false;

            i++;
            j--;
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

    bool result = list.isPalindrome();

    (result) ? cout << "it is palindrome." : cout << "it is not a palindrome.";

    return 0;
}
