/* You are given a string s, partition it in such a way that every substring is a palindrome. Return all such palindromic partitions of s */
#include <bits/stdc++.h>
using namespace std;
// Thinking is that i need to write a function that generate partitions again and again :. => Recursion
// Partition should be done keeping in mind that the left substring (fix and not further divided) is a palindrome
// We procced in a way that we make partion at the end
// We will be looping to chk that if it is possible to pation at an indx or not if yes we move on in same fashion
bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}
void func(int indx, string s, vector<string> &path, vector<vector<string>> &res)
{
    if (indx == s.size())
    {
        res.push_back(path);
        return;
    }
    for (int i = indx; i < s.size(); i++)
    {
        if (isPalindrome(s, indx, i))
        {
            path.push_back(s.substr(indx, i - indx + 1));
            func(indx + 1, s, path, res);
            path.pop_back();
        }
    }
}
vector<vector<string>> solvePartition(string s)
{
    vector<vector<string>> res;
    vector<string> path;
    func(0, s, path, res);
    return res;
}
int main()
{
    string s = "aabb";
    vector<vector<string>> res = solvePartition(s);
    for (auto &it : res)
    {
        for (auto &i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}