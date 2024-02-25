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

    vector<int> preorder(node *current)
    {
        vector<int> result;
        stack<node *> st;

        if (root == NULL)
            return result;

        while (current != NULL || !st.empty())
        {
            if (current != NULL)
            {
                st.push(current);
                current = current->left;
            }
            else
            {
                node *temp = st.top()->right;
                if (temp == NULL)
                {
                    temp = st.top();
                    st.pop();
                    result.push_back(temp->data);
                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        result.push_back(temp->data);
                    }
                }
                else
                    current = temp;
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
    bt.root->left->left->left = new node(23);
    bt.root->left->right = new node(5);
    bt.root->left->right->right = new node(45);
    bt.root->left->right->right->right = new node(78);
    bt.root->left->right->right->right->right = new node(67);
    bt.root->right->left = new node(6);
    bt.root->right->right = new node(7);

    //                  1
    //                /   \ 
    //              2       3
    //             / \     / \ 
    //            4   5   6   7
    //           /     \   
    //          23      45
    //                   \  
    //                    78
    //                     \ 
    //                      67

    vector<int> result = bt.preorder(bt.root);

    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}