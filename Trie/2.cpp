// Trie Implementation
// func : Insert, countWordEqualTo, countWordStartingWith, erase

#include<bits/stdc++.h>
using namespace std;

class Node{
private:
public:
    Node *links[26];
    int endWith = 0;
    int cntPrefix = 0;



    bool containsKey(char ch)
    {
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node *node)
    {
        links[ch-'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch-'a'];
    }

    void IncreaseEnd()
    {
        endWith++;
    }

    void IncreasePref()
    {
        cntPrefix++;
    }

    void deleteEnd()
    {
        endWith--;
    }

    void reducePrefix()
    {
        cntPrefix--;
    }

    int getEnd()
    {
        return endWith;
    }

    int getPref()
    {
        return cntPrefix;
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

        for(int i = 0; i < word.length(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->IncreasePref();
        }
        node->IncreaseEnd();
    }

    int cntWordEqualTo(string word)
    {
        Node* node = root;

        for(int i = 0; i < word.length(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }

        return node->getEnd();
    }
    

    int cntWordStartWith(string word)
    {
        Node* node = root;

        for(int i = 0; i < word.length(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }

        return node->getPref();
    }

    void erase(string word)
    {
        Node* node = root;

        for(int i = 0; i < word.length(); i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else
            {
                return;
            }
        }

        node->deleteEnd();
    }
    
};

int main()
{

}