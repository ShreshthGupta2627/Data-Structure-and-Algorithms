// You are given two arrays of non-negative integers say ‘arr1’ and ‘arr2’ of sizes N and M respectively. Find the maximum value of ( ‘A’ xor ‘B’ ) where ‘A’ and ‘B’ are any elements from ‘arr1’ and ‘arr2’ respectively and ‘xor’ represents the bitwise xor operation. Maximum XOR of Two Numbers in an Array.

#include <bits/stdc++.h>
using namespace std;
class Node{
private:
public:
    Node *links[2];

    bool containsKey(int bit)
    {
        return links[bit] != NULL;
    }

    Node *get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node* node)
    {
        links[bit] = node;
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
        for(int i = 31; i >=0; i--)
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
        for(int i = 31; i>=0; i--)
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

int maxXorSum(vector<int> &arr1, vector<int> &arr2)
{
    Trie t;

    for(auto &it : arr1)
    {
        t.insert(it);
    }

    int maxi = 0;
    for(auto &it : arr2)
    {
        maxi = max(maxi, t.getMax(it));
    }

    return maxi;
}

int main()
{
    vector<int> arr1 = {6, 8};
    vector<int> arr2 = {7, 8, 2};
    cout << maxXorSum(arr1,arr2) <<endl; 
}