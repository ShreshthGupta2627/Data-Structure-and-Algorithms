// parenthesis balances
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1 = "{([])}";
    stack<char> s;
    unordered_map<char, int> m = {{'[', -1}, {'(', -2}, {'{', -3}, {']', 1}, {')', 2}, {'}', 3}};
    for (char i : s1)
    {
        if (m[i] < 0)
        {
            s.push(i);
        }
        else
        {
            if (s.empty())
            {
                cout << "NO" << endl;
                return 0;
            }
            else
            {
                char top = s.top();
                s.pop();
                if (m[top] + m[i] != 0)
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    if (s.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}