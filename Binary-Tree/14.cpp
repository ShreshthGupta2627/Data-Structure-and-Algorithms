// Checking if two given tree are identical or not
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

bool same(Node *node1, Node *node2)
{
    if (node1 == NULL || node2 == NULL)
    {
        return (node1 == node2);
    }

    return (node1->data == node2->data && same(node1->left, node2->left) && same(node1->right, node2->right));
}
int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(-6);
    root1->right->left->left = new Node(7);
    root1->right->left->left->left = new Node(8);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(-6);
    root2->right->left->left = new Node(7);
    root2->right->left->left->left = new Node(8);

    cout << same(root1, root2) << endl;
    return 0;
}