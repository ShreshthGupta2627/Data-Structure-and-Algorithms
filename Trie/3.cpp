// Ninja developed a love for arrays and strings so this time his teacher gave him an array of strings, ‘A’ of size ‘N’. Each element of this array is a string. The teacher taught Ninja about prefixes in the past, so he wants to test his knowledge. A string is called a complete string if every prefix of this string is also present in the array ‘A’. Ninja is challenged to find the longest complete string in the array ‘A’.If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None".


// String with all prefixes


#include<bits/stdc++.h>
using namespace std;

class Node{
private:
public:
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node*node)
    {
        links[ch-'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch-'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
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

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool ifPrefExists(string word)
    {
        Node *node  = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                if(!node->isEnd())
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    // TC : O(len * n)
    Trie t;

    string a[] = {"n","ninja","ni","nin","ninj","ninga"};
    for(auto &it : a)
    {
        t.insert(it);
    }

    string longest = "";
    for(auto &it : a)
    {
        if(t.ifPrefExists(it))
        {
            if(it.length() > longest.length())
            {
                longest = it;
            }
            else if(it.length() == longest.length() && it < longest)
            {
                longest = it;
            }
        }
    }
    cout<<longest<<endl;

    return 0;
}