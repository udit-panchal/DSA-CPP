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

    void leftTraversal(node *root, vector<int> &ans)
    {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return;

        ans.push_back(root->data);

        if (root->left)
            leftTraversal(root->left, ans);
        else
            leftTraversal(root->right, ans);
    }

    void leafTraversal(node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
        }

        leafTraversal(root->left, ans);
        leafTraversal(root->right, ans);
    }

    void rightTraversal(node *root, vector<int> &ans)
    {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return;

        int temp = root->data;
        if (root->right)
            rightTraversal(root->right, ans);
        else
            rightTraversal(root->left, ans);

        ans.push_back(temp);
    }

    vector<int> boundaryTraversal(node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        ans.push_back(root->data);

        // I. left part print/ store
        leftTraversal(root->left, ans);

        // II. leaf node print / store
        //  i. left subtree
        leafTraversal(root->left, ans);
        //  ii. right subtree
        leafTraversal(root->right, ans);

        // III. print or store right part in reverse.
        rightTraversal(root->right, ans);
        return ans;
    }
};

int main()
{
    binaryTree bt;

    bt.root = new node(1);
    bt.root->left = new node(2);
    bt.root->right = new node(3);
    bt.root->left->left = new node(4);
    bt.root->left->left->left = new node(8);
    bt.root->left->right = new node(5);
    bt.root->left->right->right = new node(9);
    bt.root->right->left = new node(6);
    bt.root->right->right = new node(7);
    bt.root->right->right->right = new node(10);
    bt.root->right->right->right->right = new node(11);

    //                   1
    //                 /   \ 
    //                /     \ 
    //               /       \ 
    //              2         3
    //             / \       / \ 
    //            4   5     6   7
    //           /     \         \ 
    //          8       9        10
    //                             \ 
    //                             11


    vector<int> result = bt.boundaryTraversal(bt.root);

    for (auto num : result)
        cout << num << " ";

    return 0;
}

/*
    SOURCE : chatGPT , Love Babbar

    The boundaryTraversal function performs a counterclockwise traversal of the boundary nodes in a binary tree. It divides the traversal process into three distinct phases.

    Firstly, the left boundary traversal (leftTraversal) focuses on navigating down the left edge of the tree. It starts from the root and progresses towards the leftmost leaf node. During this traversal, it adds non-leaf nodes' data to the answer vector (ans). If a non-leaf node has a left child, it explores that subtree first; otherwise, it moves to the right child if present.

    Subsequently, the leafTraversal function is responsible for collecting all the leaf nodes in the binary tree. It performs a recursive traversal of the entire tree, systematically capturing the data of leaf nodes encountered along the way. This ensures that leaf nodes from both the left and right subtrees are included in the answer.

    Lastly, the right boundary traversal (rightTraversal) occurs in reverse order compared to the left boundary traversal. It starts from the root's right subtree and moves downwards towards the rightmost leaf node. Similar to the left traversal, non-leaf nodes' data is added to the answer vector (ans). If a non-leaf node has a right child, it explores that subtree first; otherwise, it moves to the left child if present.

    Combining these three phases, the boundaryTraversal function effectively captures the boundary nodes of the binary tree in counterclockwise order, providing a comprehensive view of the tree's exterior nodes.


*/