// Lowest Common Ancester
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node()
    {
        this->left = NULL;
        this->right = NULL;
    }

    Node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *lca(Node *root, Node *n1, Node *n2)
{
    if (root == NULL || root == n1 || root == n2)
    {
        return root;
    }

    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);

    if (left == NULL)
    {
        return right;
    }

    if (right == NULL)
    {
        return left;
    }

    return root;
}
int main()
{
    Node *root;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    Node *n1 = root->left->left = new Node(4);
    Node *n2 = root->right->right = new Node(5);
    cout << lca(root, n1, n2)->data;
    return 0;
}