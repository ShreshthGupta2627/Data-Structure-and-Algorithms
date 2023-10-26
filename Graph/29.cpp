// Word ladder 2
/*Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
Return an empty list if there is no such transformation sequence.*/

#include <bits/stdc++.h>
using namespace std;
void bfs(string startWord, string targetWord, unordered_set<string> &wl)
{
    vector<vector<string>> ans;
    queue<vector<string>> q;
    q.push({startWord});

    vector<string> UsedOnLevel;
    UsedOnLevel.push_back(startWord);
    int lvl = 0;

    while (!q.empty())
    {
        vector<string> curr = q.front();
        q.pop();

        if (curr.size() > lvl)
        {
            lvl++;
            for (auto &it : UsedOnLevel)
            {
                wl.erase(it);
            }
            UsedOnLevel.clear();
        }

        string lastWord = curr.back();
        if (lastWord == targetWord)
        {
            if (ans.size() == 0)
            {
                ans.push_back(curr);
            }
            else if (curr.size() == ans[0].size())
            {
                ans.push_back(curr);
            }
            else
            {
                return;
            }
        }
        for (int i = 0; i < lastWord.size(); i++)
        {
            char initial = lastWord[i];
            for (char j = 'a'; j <= 'z'; j++)
            {
                lastWord[i] = j;
                if (wl.find(lastWord) != wl.end())
                {
                    curr.push_back(lastWord);
                    q.push(curr);

                    // The woed is used ont this level
                    UsedOnLevel.push_back(lastWord);
                    // for next vector to be produced at same level curr should not have other :. pop it back
                    curr.pop_back();
                }
            }
            lastWord[i] = initial;
        }
    }

    for (auto &it : ans)
    {
        for (auto &t : it)
        {
            cout << t << " ";
        }
        cout << endl;
    }
}

void dfs(string &startWord, string word, vector<string> &seq, vector<vector<string>> &ans, unordered_map<string, int> &mp)
{
    if (word == startWord)
    {
        reverse(seq.begin(), seq.end());
        ans.push_back(seq);
        reverse(seq.begin(), seq.end());
        return;
    }
    for (int i = 0; i < word.size(); i++)
    {
        char org = word[i];
        int steps = mp[word];
        for (char j = 'a'; j <= 'z'; j++)
        {
            word[i] = j;
            if (mp.find(word) != mp.end() && mp[word] + 1 == steps)
            {
                seq.push_back(word);
                dfs(startWord, word, seq, ans, mp);
                // Backtrack
                seq.pop_back();
            }
        }
        word[i] = org;
    }
}
void Optimized(string startWord, string targetWord, unordered_set<string> &wl)
{
    unordered_map<string, int> mp;

    queue<string> q;
    q.push({startWord});
    mp[startWord] = 1;
    wl.erase(startWord);
    while (!q.empty())
    {
        string word = q.front();
        int steps = mp[word];
        q.pop();
        if (word == targetWord)
        {
            break;
        }
        for (int i = 0; i < word.size(); i++)
        {
            char org = word[i];
            for (char j = 'a'; j <= 'z'; j++)
            {
                word[i] = j;
                if (wl.find(word) != wl.end())
                {
                    q.push(word);
                    wl.erase(word);
                    mp[word] = steps + 1;
                }
            }
            word[i] = org;
        }
    }

    vector<vector<string>> ans;
    if (mp.find(targetWord) != mp.end())
    {
        vector<string> seq;
        seq.push_back(targetWord);
        dfs(startWord, targetWord, seq, ans, mp);
    }

    for (auto &it : ans)
    {
        for (auto &t : it)
        {
            cout << t << " ";
        }
        cout << endl;
    }
}
int main()
{
    string startWord = "der", targetWord = "dfs";
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    unordered_set<string> wl;
    for (auto &it : wordList)
    {
        wl.insert(it);
    }

    // bfs(startWord, targetWord, wl);
    Optimized(startWord, targetWord, wl);
    return 0;
}