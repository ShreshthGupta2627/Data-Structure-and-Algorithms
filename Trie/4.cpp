//  Given a string of alphabetic characters. Return the count of distinct substrings of the string(including the empty string) using the Trie data structure.

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node *links[26];

    bool containKey(char ch)
    {   
        return links[ch - 'a'] != NULL;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch , Node *node)
    {
        links[ch - 'a' ] = node;
    }
};

    int cntDistinctSubstr(string word)
    {   int cnt = 0;
        Node *root = new Node();

        for (int i = 0; i < word.length(); i++)
        {
            Node* node = root;
            for(int j = i; j < word.size(); j++)
            {
                if(!node->containKey(word[j]))
                {
                    cnt++;
                    node->put(word[j], new Node());
                }
                node = node->get(word[j]);
            }
        }
        return cnt + 1;
    }


int main()
{
    string s ="abab";
    cout << cntDistinctSubstr(s) << endl;
    return 0;
}