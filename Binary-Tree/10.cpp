// Maximum depth of binary tree
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

int height(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int hLeft = 0, hRight = 0;
    if (node->left != NULL)
    {
        hLeft = 1 + height(node->left);
    }

    if (node->right != NULL)
    {
        hRight = 1 + height(node->right);
    }

    return max(hLeft, hRight);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->left->left = new Node(8);
    // Node 1 ==> 0
    cout << height(root) << endl;
    return 0;
}