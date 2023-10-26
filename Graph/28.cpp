// Word ladder 1
/*Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
Keep the following conditions in mind:

-> A word can only consist of lowercase characters.
-> Only one letter can be changed in each transformation.
-> Each transformed word must exist in the wordList including the targetWord.
-> startWord may or may not be part of the wordList*/
#include <bits/stdc++.h>
using namespace std;
void bfs(string SW, string EW, unordered_set<string> &WL)
{
    queue<pair<string, int>> q;
    q.push({SW, 1});
    WL.erase(SW);

    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (word == EW)
        {
            cout << "Steps Count is : " << steps << endl;
        }
        for (int i = 0; i < word.size(); i++)
        {
            char curr = word[i];
            for (char k = 'a'; k <= 'z'; k++)
            {
                word[i] = k;
                if (WL.find(word) != WL.end())
                {
                    q.push({word, steps + 1});
                    WL.erase(word);
                }
            }
            // Put it back at the end of traversal else it will have z
            word[i] = curr;
        }
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
    bfs(startWord, targetWord, wl);

    // Worst case tc : wl.size() * 26 * word.size() * log(n) //Logn is for set
    return 0;
}