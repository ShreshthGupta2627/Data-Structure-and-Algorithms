// Checking for symmetric binary tree
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
bool chk(Node *l, Node *r)
{
    if (l == NULL && r == NULL)
    {
        return 1;
    }

    if (l == NULL || r == NULL)
    {
        return 0;
    }

    if (l->data != r->data)
    {
        return 0;
    }
    else
    {
        return chk(l->left, r->right) && chk(l->right, r->left);
    }
}
int main()
{
    Node *root;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->right->right = new Node(4);

    if (root == NULL)
    {
        cout << 1 << endl;
    }
    cout << chk(root->left, root->right);
    return 0;
}