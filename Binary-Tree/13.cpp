// Maximum path sum in binary tree
/*Write a program to find the maximum sum path in a binary tree. A path in a binary tree is a sequence of nodes where every adjacent pair of nodes are connected by an edge. A node can only appear in the sequence at most once. A path need not pass from the root. We need to find the path with the maximum sum in the binary tree.*/

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

int sum(Node *node, int &Maxsum)
{
    if (node == NULL)
    {
        return 0;
    }

    int leftSum = max(0, sum(node->left, Maxsum));
    int rightSum = max(0, sum(node->right, Maxsum));

    int val = node->data;

    Maxsum = max(Maxsum, leftSum + rightSum + val);

    return val + max(leftSum, rightSum);
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

    int MaxSum = INT_MIN;
    sum(root, MaxSum);

    cout << MaxSum << endl;
    return 0;
}