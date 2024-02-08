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
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        Node *temp = head;

        // iterate the original list and insert each node at the tail of the clone list
        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // mapping from original nodes to their corresponding new nodes in the clone list
        unordered_map<Node *, Node *> oldToNewNode;

        Node *originalNode = head;
        Node *cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL)
        {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        // update random pointers of the clone list nodes
        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != NULL)
        {
            cloneNode->random = oldToNewNode[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
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

    void print()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;

        cout << "Head :" << head->data << endl;
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

    Node *copyHead = list.copyList();

    // Print the original and cloned lists
    cout << "Cloned List: ";
    LinkedList copyList;
    copyList.head = copyHead;
    copyList.print();

    // Check if random pointers in the cloned list are correct
    bool randomCorrect = list.compareRandom(list.head, copyHead);
    if (randomCorrect)
    {
        cout << "Random pointers are accurately cloned." << endl;
    }
    else
    {
        cout << "Random pointers are not accurately cloned." << endl;
    }

    return 0;

    return 0;
}