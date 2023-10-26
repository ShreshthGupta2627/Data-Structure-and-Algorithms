// Accounts Merge
/*Given a list of accounts where each element account [ i ] is a list of strings, where the first element account [ i ][ 0 ]  is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order.

Note: Accounts themselves can be returned in any order.*/

#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
private:
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int Find_U_Parent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = Find_U_Parent(parent[node]);
    }
    void UnionByRank(int u, int v)
    {
        int ulp_u = Find_U_Parent(u);
        int ulp_v = Find_U_Parent(v);
        if (ulp_v == ulp_u)
        {
            return;
        }
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void UnionBySize(int u, int v)
    {
        int ulp_u = Find_U_Parent(u);
        int ulp_v = Find_U_Parent(v);
        if (ulp_v == ulp_u)
        {
            return;
        }
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
void MergedDetails(vector<vector<string>> &detail)
{
    int sz = detail.size();
    DisjointSet ds(sz);

    unordered_map<string, int> MailToNode;
    for (int i = 0; i < sz; i++)
    {
        for (int j = 1; j < detail[i].size(); j++)
        {
            string CurrMail = detail[i][j];
            if (MailToNode.find(CurrMail) == MailToNode.end())
            {
                MailToNode[CurrMail] = i;
            }
            else
            {
                ds.UnionByRank(MailToNode[CurrMail], i);
            }
        }
    }

    vector<vector<string>> merged(sz);

    for (auto &it : MailToNode)
    {
        string mail = it.first;
        int node = ds.Find_U_Parent(it.second);

        merged[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for (int i = 0; i < sz; i++)
    {
        if (merged[i].size() == 0)
        {
            continue;
        }
        else
        {
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(detail[i][0]);
            for (auto &it : merged[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
    }

    for (auto &it : ans)
    {
        for (auto &it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<string>> detail = {{"john", "j1@com", "j2@com", "j3@com"},
                                     {"john", "j4@com"},
                                     {"raj", "r1@com", "r2@com"},
                                     {"john", "j1@com", "j5@com"},
                                     {"raj", "r2@com", "r3@com"},
                                     {"marry", "m1@com"}};

    MergedDetails(detail);
    return 0;
}