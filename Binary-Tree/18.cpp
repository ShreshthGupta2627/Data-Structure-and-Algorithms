// Top view in binary tree
/*Given below is a binary tree. The task is to print the top view of the binary tree. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.*/
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> getTopView(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return {};
    }
    map<int, int> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    mp[0] = root->val;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        auto node = curr.first;
        int cnt = curr.second;

        if (mp.find(cnt) == mp.end())
        {
            mp[cnt] = node->val;
        }

        if (node->left != NULL)
        {
            q.push({node->left, cnt - 1});
        }

        if (node->right != NULL)
        {
            q.push({node->right, cnt + 1});
        }
    }

    vector<int> ans;
    for (auto &it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}