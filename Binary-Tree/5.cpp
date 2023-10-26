// Level Order Traversal
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

void LevelOrder(Node *CurrNode, queue<Node *> &q)
{
    vector<vector<int>> ans;

    q.push(CurrNode);
    while (!q.empty())
    {
        vector<int> lvl;
        lvl.clear();

        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            auto node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);

            lvl.push_back(node->data);
        }

        ans.push_back(lvl);
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    queue<Node *> q;
    LevelOrder(root, q);
    // Tc = Sc =O(n)
    return 0;
}