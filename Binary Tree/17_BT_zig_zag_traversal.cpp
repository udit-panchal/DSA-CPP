#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {

        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class binaryTree
{
public:
    node *root;

    binaryTree()
    {
        this->root = NULL;
    }

    vector<int> zig_zag_traversal(node *current)
    {
        vector<int> result;

        if (root == NULL)
            return result;

        queue<node *> q;
        q.push(root);

        bool left_to_right = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> ans(size);
            for (int i = 0; i < size; i++)
            {
                node *frontNode = q.front();
                q.pop();

                int index = 0;
                if (left_to_right == true)
                    index = i;
                else
                    index = size - i - 1;

                ans[index] = frontNode->data;

                if (frontNode->left)
                    q.push(frontNode->left);

                if (frontNode->right)
                    q.push(frontNode->right);
            }

            left_to_right = !left_to_right;

            for (auto i : ans)
            {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main()
{
    binaryTree bt;

    bt.root = new node(1);

    bt.root->left = new node(2);
    bt.root->right = new node(3);

    bt.root->left->left = new node(4);
    bt.root->left->right = new node(5);
    bt.root->left->right->right = new node(7);
    bt.root->left->right->left = new node(6);

 

    //                 1
    //               /   \ 
    //              2     3
    //             / \  
    //            4   5  
    //               / \  
    //              6   7


    vector<int> result = bt.zig_zag_traversal(bt.root);

    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}