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
        cout << endl;

        cout << "Head :" << head->data << endl;
    }


    // APPROACH - 1 : 
    
    int get_Length()
    {
        int count = 0;
        Node* temp = head;
        while(temp!= NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }


    Node* find_Middle()
    {
        int len = get_Length();
        int ans = len/2;

        Node* temp = head;
        int cnt = 0;
        while(cnt < ans)
        {
            temp = temp->next;
            cnt ++;
        }

        return temp;
    }

    // APPROACH - 2 : 

    Node* find_middle_slow_fast()
    {
        Node* slow = head;
        Node* fast = head->next;

        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
            if(fast!=NULL)
                fast = fast->next;
        }

        return slow;
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

    list.print();

    Node* ans1 = list.find_Middle();
    Node* ans2 = list.find_middle_slow_fast();

    cout<<"Middle Of LL : "<<ans1->data<<endl;
    cout<<"Middle Of LL : "<<ans2->data<<endl;


    return 0;
}