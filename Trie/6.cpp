// You are given an array/list ‘ARR’ consisting of ‘N’ non-negative integers. You are also given a list ‘QUERIES’ consisting of ‘M’ queries, where the ‘i-th’ query is a list/array of two non-negative integers ‘Xi’, ‘Ai’, i.e ‘QUERIES[i]’ = [‘Xi’, ‘Ai’]. The answer to the ith query, i.e ‘QUERIES[i]’ is the maximum bitwise xor value of ‘Xi’ with any integer less than or equal to ‘Ai’ in ‘ARR’. You should return an array/list consisting of ‘N’ integers where the ‘i-th’ integer is the answer of ‘QUERIES[i]’.

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* links[2];

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }

    Node *get(int bit)
    {
        return links[bit];
    }

    bool containsKey(int bit)
    {
        return links[bit] != NULL;
    }
};

class Trie{
private:
    Node *root;
public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if(!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *node = root;

        int maxSum = 0;
        for(int i = 31; i >=0; i--)
        {   
            int bit = (num >> i) & 1;
            if(node->containsKey(1-bit))
            {
                maxSum = maxSum | (1 << i);
                node = node->get(1-bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxSum;
    }
};

int main()
{
    int n = 5,q = 2;
    vector<int>v = {0,1,2,3,4};
    vector<pair<int,int>>p = {{1,3},{5,6}};

    sort(v.begin(), v.end());
    vector<pair<int,pair<int,int>>>Offlinequery;
    for(int i = 0; i < q; i++)
    {
        Offlinequery.push_back({p[i].second, {p[i].first, i}});
    }
    sort(Offlinequery.begin(), Offlinequery.end());

    vector<int>ans(q,0);

    Trie t;
    int ind = 0;
    for(int i = 0; i < q; i++)
    {
        int ai = Offlinequery[i].first;
        int xi = Offlinequery[i].second.first;
        int qInd = Offlinequery[i].second.second;

        while (ind < n && v[ind] < ai)
        {
            t.insert(v[ind]);
            ind++;
        }
        if(ind == 0)
        {
            ans[qInd] = -1;
        }
        else
        {
            ans[qInd] = t.getMax(xi);
        }
    }
    
    for(auto &it : ans)
    {
        cout<<it<<" ";
    }
    return 0;
}