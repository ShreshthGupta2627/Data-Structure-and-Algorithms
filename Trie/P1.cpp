#include <bits.stdc++.h>
using namespace std;
class Node
{
private:
    bool flag = false;

public:
    Node *link[26];
    bool containKey(char ch)
    {
        return link[ch - 'a'] != NULL;
    }

    void put(char ch, Node *neww)
    {
        link[ch - 'a'] = neww;
    }

    Node *get(char ch)
    {
        return link[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool getEnd()
    {
        return flag;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node;
    }

    void insert(string word)
    {
        Node *root1 = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!root1->containKey(word[i]))
            {
                root1->put(word[i], new Node());
            }
            root1 = root1->get(word[i]);
        }

        root1->setEnd();
    }

    bool isPresent(string word)
    {
        Node *root1 = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!root1->containKey(word[i]))
            {
                return false;
            }
            root1 = root1->get(word[i]);
        }
        return root1->getEnd();
    }

    int pref()
    {
        Node *root1 = root;

        int cnt = 0;
        while (1)
        {
            int temp = 0;
            for (int i = 0; i < 26; i++)
            {
                if (root1->link[i] != NULL)
                {
                    temp++;
                }
            }

            if (temp > 1)
            {
                return cnt;
            }
            cnt++;
        }
        return cnt;
    }
};
class Solution
{
public:
    string longestCommonPrefix(vector<string> &s)
    {
        Trie t;
        for (auto &it : s)
        {
            t.insert(it);
        }
        cout << t.pref();
        return "";
    }
};