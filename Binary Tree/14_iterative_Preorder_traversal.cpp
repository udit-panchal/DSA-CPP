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

    vector<int> preorder(Node *root)
    {
        vector<int> result;
        if (root == NULL)
            return result;

        stack<Node *> st;
        st.push(root);

        while (!st.empty())
        {
            root = st.top();
            st.pop();

            result.push_back(root->data);

            if (root->right != NULL)
                st.push(root->right);

            if (root->left != NULL)
                st.push(root->left);
        }
        return result;
    }
};

int main()
{

    BinaryTree bt;

    bt.root = new Node(1);

    bt.root->left = new Node(2);
    bt.root->right = new Node(3);

    bt.root->left->left = new Node(4);
    bt.root->left->left->left = new Node(23);
    bt.root->left->right = new Node(5);
    bt.root->left->right->right = new Node(45);
    bt.root->left->right->right->right = new Node(78);
    bt.root->left->right->right->right->right = new Node(67);
    bt.root->right->left = new Node(6);
    bt.root->right->right = new Node(7);

    ///////////////////////////////////
    //                               //
    //                               //
    //               1               //
    //             /   \             //
    //           2       3           //
    //          / \     / \          //
    //         4   5   6   7         //
    //        /     \                //
    //       23      45              //
    //                \              //
    //                 78            //
    //                  \            //
    //                   67          //
    //                               //
    //                               //
    ///////////////////////////////////

    vector<int> result = bt.preorder(bt.root);

    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
