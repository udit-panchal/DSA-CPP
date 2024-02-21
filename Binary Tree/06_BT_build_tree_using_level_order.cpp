#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = nullptr;
    }

    void build_with_level_order(Node *&root)
    {

        queue<Node *> q;

        cout << "Enter data : ";
        int data;
        cin >> data;
        cout << endl;

        root = new Node(data);
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            cout << temp->data << "->Left : ";
            int leftData = 0;
            cin >> leftData;

            if (leftData != -1)
            {
                temp->left = new Node(leftData);
                q.push(temp->left);
            }

            cout << temp->data << "->Right : ";
            int rightData = 0;
            cin >> rightData;

            if (rightData != -1)
            {
                temp->right = new Node(rightData);
                q.push(temp->right);
            }
        }
    }
};

int main()
{

    BinaryTree bt;

    bt.build_with_level_order(bt.root);

    return 0;
}