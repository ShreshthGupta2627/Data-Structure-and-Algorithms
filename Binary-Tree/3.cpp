// Post Order Traversal of bt
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

void PostOrder(Node *CurrNode)
{
    if (CurrNode == NULL)
    {
        return;
    }
    PostOrder(CurrNode->left);
    PostOrder(CurrNode->right);
    cout << CurrNode->data << " ";
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    PostOrder(root);
    // Tc = Sc =O(n)
    return 0;
}