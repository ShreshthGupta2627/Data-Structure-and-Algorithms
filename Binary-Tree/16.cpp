// Boundary Traversal of a Binary Tree
/* Write a program for the Anti-Clockwise Boundary traversal of a binary tree.*/

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left, *right;
    int data;

    Node(int val)
    {
        left = right = NULL;
        data = val;
    }
};

bool isLeaf(Node *node)
{
    if (node->left == NULL && node->right == NULL)
    {
        return 1;
    }
    return 0;
}
void addLeftNode(Node *node, vector<int> &BoundryTrav)
{
    auto l = node->left;
    while (l)
    {
        if (!isLeaf(l))
        {
            BoundryTrav.push_back(l->data);
        }
        if (l->left)
        {
            l = l->left;
        }
        else
        {
            l = l->right;
        }
    }
}
void addLeafNode(Node *root, vector<int> &BoundryTrav)
{
    if (isLeaf(root))
    {
        BoundryTrav.push_back(root->data);
        return;
    }
    if (root->left)
        addLeafNode(root->left, BoundryTrav);
    if (root->right)
        addLeafNode(root->right, BoundryTrav);
}
void addRightNode(Node *node, stack<int> &st, vector<int> &BoundryTrav)
{
    auto r = node->right;
    while (r)
    {
        if (!isLeaf(r))
        {
            st.push(r->data);
        }

        if (r->right)
        {
            r = r->right;
        }
        else
        {
            r = r->left;
        }
    }

    while (!st.empty())
    {
        int data = st.top();
        st.pop();

        BoundryTrav.push_back(data);
    }
}
void BoundryT(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    vector<int> BoundryTrav;
    if (!isLeaf(root))
    {
        BoundryTrav.push_back(root->data);
    }

    addLeftNode(root, BoundryTrav);
    addLeafNode(root, BoundryTrav);
    stack<int> temp;
    addRightNode(root, temp, BoundryTrav);

    for (auto &it : BoundryTrav)
    {
        cout << it << " ";
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->left->left = new Node(10);
    root->right->right->left->right = new Node(11);

    BoundryT(root);
    return 0;
}