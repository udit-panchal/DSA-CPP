#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
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

            while (count < position)
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

    // function to copy the linked list with random pointers
    Node *copyList()
    {
        // step 1 : create a clone list
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        Node *temp = head;
        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // step 2 : cloneNodes add in betwee original list
        Node *originalNode = head;
        Node *cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL)
        {
            Node *forw = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = forw;

            if (originalNode)
                forw = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = forw;
        }

        // step 3 : random pointer copy
        temp = head;
        while (temp != NULL)
        {
            if (temp->next != NULL)
                temp->next->random = temp->random ? temp->random->next : temp->random;

            temp = temp->next;
        }

        // step 4 : revert changes done in step 2
        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != NULL && cloneNode != NULL)
        {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if (originalNode != NULL)
            {
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }

        // step 5 :

        return cloneHead;
    }

    // function to compare random pointers of two lists
    bool compareRandom(Node *original, Node *clone)
    {
        // Traverse both original and cloned lists
        while (original && clone)
        {
            // If random pointers don't match or match but to different addresses, return false
            if (original->random == nullptr && clone->random != nullptr)
                return false;
            if (original->random != nullptr && clone->random == nullptr)
                return false;
            if (original->random && clone->random && original->random->data != clone->random->data)
                return false;

            // Move to the next nodes
            original = original->next;
            clone = clone->next;
        }
        // If one list has ended and the other hasn't, they are not equal
        return (original == nullptr && clone == nullptr);
    }

    // void print()
    // {
    //     Node *temp = head;

    //     while (temp != NULL)
    //     {
    //         cout << temp->data << " -> ";
    //         temp = temp->next;
    //     }
    //     cout << endl;

    //     cout << "Head :" << head->data << endl;
    // }

    void print(Node *listHead)
    {
        Node *temp = listHead;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    // random pointers are created
    list.head->random = list.head->next->next;                         // node1->node3
    list.head->next->random = list.head;                               // node2->node1
    list.head->next->next->random = list.head->next->next->next->next; // node3->node5
    list.head->next->next->next->random = list.head->next->next;       // node4->node3
    list.head->next->next->next->next->random = list.head->next->next; // node5->node3

    cout << "Original List: ";
    list.print(list.head);

    // Print the original and cloned lists
    Node *copyHead = list.copyList();

    cout << "Cloned List:  ";
    list.print(copyHead);

    // list.print();

    // Check if random pointers in the cloned list are correct (TESTING)
    bool randomCorrect = list.compareRandom(list.head, copyHead);
    (randomCorrect) ? cout << "Random pointers are accurately cloned." : cout << "Random pointers are not accurately cloned." << endl;

    return 0;
}