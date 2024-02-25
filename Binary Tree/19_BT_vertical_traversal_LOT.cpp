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
        this->left = nullptr;
        this->right = nullptr;
    }
};

class binaryTree
{
public:
    node *root;

    binaryTree()
    {
        this->root = nullptr;
    }

    vector<int> verticalTravesal(node *root)
    {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<node *, pair<int, int>>> q;
        vector<int> result;

        if (root == nullptr)
        {
            return result;
        }

        q.push({root, {0, 0}});

        while (!q.empty())
        {

            pair<node *, pair<int, int>> temp = q.front();
            q.pop();

            node *frontNode = temp.first;
            int horizontal_Dist = temp.second.first;
            int vertical_level = temp.second.second;

            nodes[horizontal_Dist][vertical_level].push_back(frontNode->data);

            if (frontNode->left)
                q.push({frontNode->left, {horizontal_Dist - 1, vertical_level + 1}});

            if (frontNode->right)
                q.push({frontNode->right, {horizontal_Dist + 1, vertical_level + 1}});
        }

        for (auto i : nodes)
            for (auto j : i.second)
                for (auto k : j.second)
                    result.push_back(k);

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


    vector<int> result = bt.verticalTravesal(bt.root);

    for (auto num : result)
        cout << num << " ";

    return 0;
}

/* Source : ChatGPT

    vertical traversal of a binary tree

    Organizing nodes based on their horizontal distance and vertical level. It employs a  level-order traversal approach, starting from the root node and iteratively processing each level.

    The function utilizes a map of maps to store nodes, where the outer map's keys represent the    horizontal distance from the root, and the inner map's keys represent the vertical level within    each horizontal distance. Nodes are stored in vectors within this structure.

        --++-----------------------------------------------------------------------++--
          ||  map < horizontal_distance, map < level, node*->data > > mapping ;    ||
        --++-----------------------------------------------------------------------++--

    Traversal begins by push the root node with horizontal distance and vertical level. While the queue is not empty, current node is store in temp and queue are pop, and their data is inserted into the appropriate position in the map. For each pop node, its children are push with updated horizontal distances and vertical levels.

    Once traversal completes, the function flattens the map structure, iterating over each level and each node within that level to populate a result vector. This vector contains node data ordered vertically, facilitating easy retrieval of nodes from the binary tree in a vertical order. This approach ensures efficient organization and retrieval of nodes based on their positions within the binary tree's structure.


*/