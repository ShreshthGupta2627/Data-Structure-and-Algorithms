// Checking balanced nature of bt
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
    return 1 + max(height(node->left), height(node->right));
}
bool balanced(Node *node)
{
    if (node == NULL)
    {
        return 1;
    }
    int lh = 0, rh = 0;
    if (node->left)
    {
        lh = height(node->left);
    }

    if (node->right)
    {
        rh = height(node->right);
    }

    if (abs(lh - rh) > 1)
    {
        return 0;
    }

    bool left = balanced(node->left);
    bool right = balanced(node->right);

    if (!left || !right)
    {
        return false;
    }

    return 1;
}

int On_chk(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int lh = height(node->left);
    int rh = height(node->right);
    if (lh == -1 || rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);

    // if -1 its not balanced
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

    cout << balanced(root) << endl;

    return 0;
}