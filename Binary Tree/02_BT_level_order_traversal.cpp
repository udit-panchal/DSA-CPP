#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
    
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        this->root = NULL;
    }

    void levelOrderTraversal()
    {
        // Check if Tree is empty
        if (root == nullptr)
            return;

        // Creating a queue
        queue<Node*> q;

        // Inserting root node
        q.push(root);
        q.push(nullptr);

        // Loop until all element can't print
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();

            if(temp == nullptr)
            {
                cout<<endl;
                if(!q.empty())
                {
                    q.push(nullptr);
                }
            }
            else{
                cout<<temp->data<<" ";
                
                if(temp->left != nullptr)
                    q.push(temp->left);
                
                if(temp->right != nullptr)
                    q.push(temp->right);
            }
        }
    }
};

int main()
{

    BinaryTree bt;
    bt.levelOrderTraversal();
    return 0;
}