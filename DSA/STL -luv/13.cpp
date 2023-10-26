// Stack and queue
#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;
    // LIFO
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    // deleting all elements of stack
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    queue<string> q;
    // FIFO
    q.push("abc");
    q.push("bcd");
    q.push("cde");
    q.push("def");
    q.push("ghi");
    // deleting all elements of queue
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}